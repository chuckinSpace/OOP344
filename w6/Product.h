// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email: cmoyano-rugiero@mysenecac.ca
// Date of completion: 10-31-18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W6_PRODUCT_H
#define W6_PRODUCT_H



#include <iostream>
#include "iProduct.h"

namespace w6{
    
    class Product : public iProduct {
        double _pPrice;
        std::string _pNumber;
        
    public:
        Product(std::string pNum, const double price);
        double getPrice() const;
        void display(std::ostream& os) const;
        
    
    };
    
}


#endif /* W6_PRODUCT_H */
