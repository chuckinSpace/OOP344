// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email: cmoyano-rugiero@myseneca.ca
// Date of completion: 10-4-18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W4_NOTIFICATIONS_H
#define W4_NOTIFICATIONS_H

#include <iostream>
#include <fstream>
#include "Message.h"
namespace w4 {
    
    const size_t maxmessages = 10;
    
    class Notifications {
        
        
        Message *my_Messages;
        size_t count;
        
    public:
        Notifications();
        Notifications(const Notifications& source);
        Notifications& operator=(const Notifications& source );
        Notifications(Notifications&& source);
        Notifications& operator=(Notifications&& source);
        ~Notifications();
        void operator+=(const Message& msg);
        void display(std::ostream& os) const;
        
    };
}

#endif /* W4_NOTIFICATIONS_H */
