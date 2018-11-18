// Name:Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email: cmoyano-rugiero@myseneca.ca
// Date of completion: 11-16-18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <memory>
#include <algorithm>
#include "List.h"
#include "Element.h"
#include "Utilities.h"


using namespace std;

namespace w8
{
    List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price)
    {
        List<Product> priceList;
        // TODO: Add your code here to build a list of products
        //         using raw pointers
        
        for(size_t i = 0 ;i < desc.size() ; i++)
        {
            for(size_t j = 0 ;j < price.size() ; j++)
            
            {
                if(desc[i].code == price[j].code)
                {
                    
                    Product* temp = new Product(desc[i].desc,price[j].price);
                    temp->validate();
                    priceList += temp;
                    delete temp;
                    temp = nullptr;
                    
                }
           
            }
        }
        
        
        return priceList;
    }
    
    List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price)
    {
        List<Product> priceList;
        // TODO: Add your code here to build a list of products
        //         using smart pointers
        for(size_t i = 0; i < desc.size() ; i++){
            for(size_t j = 0;j < price.size() ; j++){
                if(desc[i].code == price[j].code)
                {
                    
                    Product* ptr = new Product(desc[i].desc,price[j].price);
                    std::unique_ptr<Product> temp(ptr);
                    temp->validate();
                    priceList += std::move(temp);
                    
                }
                
            }

        }
        return priceList;
    }
}
