// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email: cmoyano-rugiero@mysenecac.ca
// Date of completion: 10-31-18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W6_TAXABLEPRODUCT_H
#define W6_TAXABLEPRODUCT_H

#include <iostream>
#include <array>
#include "Product.h"



//inherits display, getprice, and adds tax
namespace w6{
    class TaxableProduct : public Product {
       
        char _taxType;
        std::array<double,2> taxes {{0.08, 0.13}};
    public:
        TaxableProduct(std::string ProductNumber,double ProductPrice, char TaxableCode);
        void display(std::ostream& os) const;
        double getPrice() const;
        
    };
    
}


#endif /* TAXABLEPRODUCT_H */
