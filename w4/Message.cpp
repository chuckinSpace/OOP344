// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email: cmoyano-rugiero@myseneca.ca
// Date of completion: 10-4-18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Message.h"

using namespace std;

namespace w4{

    Message::Message(){
        setEmpty();
    }
    
    Message::Message(ifstream& in, char c){
      
        if(in.is_open() && in.good()){
        
            string line;
            getline(in, line, c);  // getting the whole line from file
            istringstream istr(line);
            //storing until first space as user
            istr >> _user;
            
            // deleting our line size_til the lenght of the _user just copied
            size_t userLenght = _user.length();
            line.erase(0,userLenght+1);
            // if @ found get index, start after @ and copy to _reply until the space
            size_t mySpaceIndex = line.find(' ');
            if(line.find('@') != std::string::npos){
                for(size_t i = 1; i < mySpaceIndex ; ++i){
                    _reply += line[i];
                }
                line.erase(0,mySpaceIndex + 1);  // deleting our line until after _reply and space
            }
            
            // find \r get index, use it to copy tweet until \r
            size_t myReturnIndex = line.find('\r');
            if(myReturnIndex != std::string::npos){
                for (size_t i = 0; i < myReturnIndex + 1; ++i){
                        _tweet += line[i];
                }
            }
                
        }
    }
    
    
        
    void Message::setEmpty(){
     
        _user = "";
        _tweet = "";
        _reply = "";
        
    }
   
    bool Message::empty() const{
      // if no tweet true
        return  _tweet.empty();
        
    }
      
    void Message::display(std::ostream& os) const{
                      
        os << "Message" << endl;
        os << " User  : " << _user << endl;
        if(!_reply.empty()){
            os << " Reply : " << _reply << endl;
        }
        os << " Tweet : " << _tweet << endl;
        
        os << endl;
                      
    }
                  
}

   


