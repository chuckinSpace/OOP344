// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email: cmoyano-rugiero@myseneca.ca
// Date of completion: 11-23-18
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

#include <iostream>
#include "Item.h"

struct ItemInfo
{
    std::string m_itemName;
    unsigned int m_serialNumber = 0;
    bool m_fillState = false;
    
    ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder {
  
    std::string m_name;
    std::string m_product;
    unsigned int m_cntItem = 1 ;
    ItemInfo** m_lstItem = nullptr;
    static size_t m_widthField;
    
public:
    CustomerOrder();
    CustomerOrder(std::string& record);
    CustomerOrder(const CustomerOrder& src);
    CustomerOrder& operator=(const CustomerOrder& src) = delete;
    CustomerOrder(CustomerOrder&& src) noexcept;
    CustomerOrder& operator=(CustomerOrder&& src);
    ~CustomerOrder();
    bool getItemFillState(std::string) const;
    bool getOrderFillState() const;
    void fillItem(Item& item,std::ostream&);
    void display(std::ostream&) const;
    void updateWidthCustomer(size_t size)const;
    std::string getName() const;
    
    
};



#endif /* CUSTOMERORDER_H */
