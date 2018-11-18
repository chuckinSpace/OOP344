// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email: cmoyano-rugiero@mysenecac.ca
// Date of completion: 10-31-18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <iomanip>
#include "Product.h"

using namespace std;

namespace w6{
    
    Product::Product(string pNum, const double price){
        _pPrice = price;
        _pNumber = pNum;
    }
    double Product::getPrice()const{
        return _pPrice;
    }
    void Product::display(std::ostream& os) const{
        os  << std::right << std::setw(16) << _pNumber << std::setprecision(2) << std::setw(16) << _pPrice;
    }
   
}

