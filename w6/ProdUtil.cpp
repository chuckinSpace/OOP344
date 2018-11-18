// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email: cmoyano-rugiero@mysenecac.ca
// Date of completion: 10-31-18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <fstream>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include "ProdUtil.h"
#include "Product.h"
#include "TaxableProduct.h"

using std::string;
using std::cout;

namespace w6 {
    


std::ostream& operator<<(std::ostream& os, const iProduct& myProduct){
   
    myProduct.display(os);
    std::cout << std::endl;
    
    return os;
}

w6::iProduct *readProduct(std::ifstream &in)
    {
        std::string line;
        std::getline(in, line);
       
        
        if(!line.empty()){
            std::istringstream stream(line);
            std::string tempProductNumber;
            double tempProductPrice;
            char tempTaxableCode;
            w6::iProduct* tempProduct;
            
            stream >> tempProductNumber >> tempProductPrice >> tempTaxableCode;
            if(tempTaxableCode == 'H' || tempTaxableCode == 'P'){
                tempProduct = new w6::TaxableProduct(tempProductNumber,tempProductPrice,tempTaxableCode);
            }else if(tempTaxableCode == 'C' || tempTaxableCode == 'M'){
                
                throw std::string("Unrecognizable Tax Code!");
                
                
            }else{
                tempProduct = new w6::Product(tempProductNumber, tempProductPrice);
            }
                return tempProduct;
        }else{
            throw std::string("no such record! Reached the end of the file!");
            
        }
        return nullptr;
    }

}
