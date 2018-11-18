// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email: cmoyano-rugiero@myseneca.ca
// Date of completion: 11-17-18
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include <iostream>
#include <sstream>
#include <vector>
#include "Utilities.h"

using namespace std;

char Utilities::m_delimiter = ' ';
size_t Utilities::Ut_next_pos = 0;

void Utilities::setFieldWidth(size_t width){
    m_widthField = width;
}
size_t Utilities::getFieldWidth() const{
    return m_widthField;
}
const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more){
    
    bool keepReading = more;
    std::istringstream stream(str);
    std::string line;
    // set the initial position of the stream to the static memberholding the last position read
    stream.seekg(Ut_next_pos);
    try{
        
        if(keepReading){
            getline(stream,line,m_delimiter);
            //update the stream position by using tellg()
            Ut_next_pos = stream.tellg();
            if(m_widthField < line.size()){
                m_widthField = line.size();
            }
            if(line == " " || line == "")
                throw std::string("No token between expression");
            }else{
                keepReading = false;
            }
            
    }catch(std::string message){
        cout << message << endl;
    }
    
    return line;
}
void Utilities::setDelimiter(const char myDelimiter){
    m_delimiter = myDelimiter;
}
const char Utilities::getDelimiter() const{
    return m_delimiter;
}
void Utilities::setPosition(size_t position) {
     Ut_next_pos = position;
}
