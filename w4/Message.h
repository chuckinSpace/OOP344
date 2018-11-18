// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email: cmoyano-rugiero@myseneca.ca
// Date of completion: 10-4-18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W4_MESSAGE_H
#define W4_MESSAGE_H

#include <iostream>
#include <fstream>

namespace w4 {
    
 class Message {
        
     std::string _user;
     std::string _tweet;
     std::string _reply;
     
    public:
        Message();
        Message(std::ifstream& in, char c);
        bool empty() const;
        void display(std::ostream& os) const;
        void setEmpty();
        unsigned long searchIndex(std::string line, char delimiter)const;
       
        
    };

}

#endif /* W4_MESSAGE_H */
