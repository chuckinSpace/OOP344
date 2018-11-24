// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email: cmoyano-rugiero@myseneca.ca
// Date of completion: 11-23-18
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include <iostream>
#include <sstream>
#include <vector>
#include "Utilities.h"

using namespace std;

char Utilities::m_delimiter = ' ';


void Utilities::setFieldWidth(size_t width){
    m_widthField = width;
}
size_t Utilities::getFieldWidth() const{
    return m_widthField;
}
const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more){
    
        std::string token = str.substr(next_pos);
        size_t delimiterPos = token.find(m_delimiter);
        token = token.substr(0, delimiterPos);
        if(token.empty())
        {
            throw std::string("No token found between expressions");
        }
        next_pos += token.size() + 1;
        next_pos < str.size() - 1 ? more = true : more = false;
    
        size_t newSize = token.size();
        if(token[newSize-1] == '\r')
        {
            std::string tempString = token.substr(0,newSize-1);
            more = false;
            return tempString;
        }
    
        return token;
}
void Utilities::setDelimiter(const char myDelimiter){
    m_delimiter = myDelimiter;
}
const char Utilities::getDelimiter() const{
    return m_delimiter;
}
