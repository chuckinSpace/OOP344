// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email: cmoyano-rugiero@myseneca.ca
// Date of completion: 10-4-18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include "Notifications.h"
#include "Message.h"

using namespace std;

namespace w4 {
    Notifications::Notifications(){
        count = 0 ;
        my_Messages = nullptr;
    }
    Notifications::Notifications(const Notifications& source){
        *this = source;
    }
    Notifications& Notifications::operator=(const Notifications& source ){
        if(this != &source){
            my_Messages = new Message [maxmessages];
            for (size_t  i = 0 ; i < maxmessages; ++i){
                this->my_Messages[i] = source.my_Messages[i];
                count = source.count;
            }
        }
        return *this;
    }
    Notifications::Notifications(Notifications&& source){
        *this = move(source);
    }
   
    Notifications::~Notifications(){
        delete [] my_Messages;
    }
    Notifications& Notifications::operator=(Notifications&& source){
        if(this != &source){
            delete [] my_Messages;
            my_Messages = new Message [maxmessages];
            for (size_t  i = 0 ; i < maxmessages; ++i){
                this->my_Messages[i] = source.my_Messages[i];
            }
            this->count = source.count;
            source.my_Messages = nullptr;
           
        }
        return *this;
    }
    void Notifications::display(std::ostream& os) const{
        for(size_t i = 0 ; i < count ; ++i){
            my_Messages[i].display(os);
         }
    }
        
    void Notifications::operator+=(const Message& msg){
        if(count == 0){
            my_Messages = new Message [maxmessages];
        }
        if(count < maxmessages){
             my_Messages[count] = msg;
             count++;
        }
   }
}
