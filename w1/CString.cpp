// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email:  cmoyano-rugiero@myseneca.ca
// Date of completion: 11-9-18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
#include <iostream>
#include "CString.h"


int STORED = w1::MAX;


namespace w1{
    
    
    Cstring::Cstring( const char* mystring){
   
        if(mystring[0] == '\0'){
            
            myChar[0] = '\0';
        
        }else{
            
            for(int i = 0 ; i < MAX ; i++){
            
               myChar[i] = mystring[i];
             }
            myChar[MAX] = '\0';
        }
    }
    void Cstring::display(std::ostream& os) const{
        
        os << myChar;
    }
    std::ostream &operator<<(std::ostream &os, const Cstring &mystring){
        
        static int count = 0 ;
        os << count <<": ";
        count++;
        
        mystring.display(os);
        
        return os;
        
    }
}
