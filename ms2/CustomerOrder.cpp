// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email: cmoyano-rugiero@myseneca.ca
// Date of completion: 11-23-18
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#include <iomanip>
#include <vector>
#include "CustomerOrder.h"
#include "Utilities.h"



size_t CustomerOrder::m_widthField = 0;

using namespace std;
// default contructor setting to empty states
CustomerOrder::CustomerOrder() : m_name(""), m_product(""), m_cntItem(0), m_lstItem(nullptr)
{
  
}
CustomerOrder::CustomerOrder(std::string& record){
   // try catch to catch error from extract token
    try{
            if(!record.empty())
            {
                Utilities myTempObj;
                size_t next_pos = 0;
                bool more = true;
                //declaring a vector to store itemInfo pointers
                std::vector<ItemInfo*>tempVector;
            
                if(more){m_name = myTempObj.extractToken(record,next_pos,more);}
                updateWidthCustomer(m_name.size());
                
                if(more){m_product = myTempObj.extractToken(record,next_pos,more);}
                updateWidthCustomer(m_product.size());
                // while more is true keep extracting item info items
                //more is set to false from Utilities::extractoken, then line finished
                
                while(more)
                {
                    std::string tempName = myTempObj.extractToken(record,next_pos,more);
                    if(!tempName.empty()){
                        ItemInfo* tempInfoItem = new ItemInfo(tempName);
                        tempVector.push_back(tempInfoItem);
                    }
                }
                
                    m_cntItem = (int)tempVector.size();
                    m_lstItem = new ItemInfo*[m_cntItem];
                    for(size_t i = 0; i < m_cntItem;++i)
                    {
                        m_lstItem[i] = tempVector[i];
                    }
                }
        }catch(std::string str){
            std::cout<< str;
    }
}

   
// copy contructor has to throw exception
CustomerOrder::CustomerOrder(const CustomerOrder& src){
    throw 1;
}

CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept{
    *this = std::move(src);
}
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src){
    if(this != &src)
    {
        delete [] m_lstItem;
        m_name = src.m_name;
        m_product = src.m_product;
        m_cntItem = src.m_cntItem;
        m_lstItem = src.m_lstItem;
        
        src.m_lstItem  = nullptr;
    
    }
    
    return *this;
    
}
  
CustomerOrder::~CustomerOrder(){
    delete [] m_lstItem;
}

bool CustomerOrder::getItemFillState(std::string item) const{
   
  
    for(size_t i = 0; i < m_cntItem; ++i)
    {
        if(item == m_lstItem[i]->m_itemName)
        {
            return m_lstItem[i]->m_fillState;
        
        }else{
            return true;
        }
    }
    return true;
}




bool CustomerOrder::getOrderFillState() const{
    unsigned int counter = 0;
       for(size_t i = 0; i < m_cntItem; ++i)
       {
           if(m_lstItem[i]->m_fillState)
                counter++;
       }
    if(counter == m_cntItem){
        return true;
    }
    else{
        return false;
    }
}
void CustomerOrder::fillItem(Item& item,std::ostream& os){
    
    std::string itemName = item.getName();
    unsigned int itemQty = item.getQuantity();
    unsigned int serialNumber = item.getSerialNumber();
    
    for(size_t i = 0; i < m_cntItem; ++i)
    {
        if((itemName == m_lstItem[i]->m_itemName) && itemQty > 0)
        {
            this->m_lstItem[i]->m_fillState = true;
            item.updateQuantity();
            m_lstItem[i]->m_serialNumber = serialNumber;
            
            os << "Filled " << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]" << endl;
            
            break;
            
        }else if(itemName == m_lstItem[i]->m_itemName){
            
            os << "Unable to fill " << m_name << m_product << "[" << m_lstItem[i]->m_itemName << "]" << endl;
            
            break;
        }
    }
}
 
void CustomerOrder::display(std::ostream& os) const{
    
    os << m_name << " - " << m_product << endl;
    
    for(size_t i = 0; i < m_cntItem; ++i)
    {
        os << setfill('0') << setw(6) << "[" << m_lstItem[i]->m_serialNumber << "] " <<
        setfill(' ') << setw((int)m_widthField);
        os << m_lstItem[i]->m_itemName;
        os << " - ";
         if(m_lstItem[i]->m_fillState){
             os << "FILLED";
             
         }else{
             os << "MISSING";
         }
        os << endl;
    }
}

void CustomerOrder::updateWidthCustomer(size_t size) const {
    
    if(size > m_widthField){
        m_widthField = (unsigned int)size;
    }
}
std::string CustomerOrder::getName() const{
    return m_name;
}
