// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email: cmoyano-rugiero@myseneca.ca
// Date of completion: 11-17-18
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include "Utilities.h"
#include "Item.h"



using namespace std;

unsigned int Item::m_widthField = 0;


Item::Item(): m_name(""), m_description(""), m_serialNumber(0), m_quantity(0)
{
   
}

Item::Item(const std::string& record){
    // creating Utility object to call extractToken
    Utilities myTempObj;
    size_t next_pos = 0;
    bool more = true;
    // read token returns string, creating temp strings to hold them
    std::string temp_serial;
    std::string temp_quantity;
    
    // only name and quantity control the width, serial and description dont.
    m_name = myTempObj.extractToken(record,next_pos,more);
    updateWidth(m_name.size());
    
    // function returns string, using temp to cast after to unsigned integers
    temp_serial = myTempObj.extractToken(record,next_pos,more);
    
    temp_quantity = myTempObj.extractToken(record,next_pos,more);
    updateWidth(temp_quantity.size());
    
    m_description = myTempObj.extractToken(record,next_pos,more);
    
    // casting to integers
    m_serialNumber = atoi(temp_serial.c_str());
    m_quantity = atoi(temp_quantity.c_str());
    
    //setting the static member of the utility object to 0 to start a new object(line)
    myTempObj.setPosition(0);
    
    
}
const std::string& Item::getName() const{
    return m_name;
}
const unsigned int Item::getSerialNumber(){
    return m_serialNumber++;
}
const unsigned int Item::getQuantity(){
    return m_quantity;
}
void Item::updateQuantity(){
    m_quantity--;
}
void Item::display(std::ostream& os, bool full) const{
    if (!full){
        os <<  left << setfill(' ') << setw(m_widthField+1) << m_name;
        os <<  "[" <<  setfill('0') << setw(6) << right << m_serialNumber << "]" << endl;
    }else{
      
        os << left << setfill(' ') << setw(m_widthField+1) << m_name;
        os << "["  << setfill('0') << setw(6) << right  << m_serialNumber << "]";
        os << left << setfill(' ') << " Quantity: " << setw(m_widthField+1) << m_quantity;
        os << "Description: " << m_description << endl;
        }
}
void Item::updateWidth(size_t size){
    if(m_widthField < size)
        m_widthField = (unsigned int)size;
}
