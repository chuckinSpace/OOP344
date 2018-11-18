// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email: cmoyano-rugiero@mysenecac.ca
// Date of completion: 10-31-18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include "TaxableProduct.h"

using namespace std;

namespace w6 {

   TaxableProduct::TaxableProduct(string ProductNumber,double ProductPrice, char TaxableCode):Product(ProductNumber,ProductPrice)
    {
        
        _taxType = TaxableCode;
        
        
    }
  
    double TaxableProduct::getPrice() const {
        double tax_p = 0.00;
        if(_taxType == 'H'){
            
            tax_p = Product::getPrice() + (Product::getPrice() * taxes[1]);
        }
        else if (_taxType == 'P') {
            tax_p = Product::getPrice() + (Product::getPrice() * taxes[0]);
        }
        else {
            tax_p = Product::getPrice();
        }
        return tax_p;
    }
    void TaxableProduct::display(std::ostream& os) const {
        Product::display(os);
        std::string hst = " HST";
        std::string pst = " PST";
        if (_taxType == 'H') {
            os << hst;
        }
        else {
            os << pst;
        }
        
    }
 
}
