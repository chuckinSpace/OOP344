// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email: cmoyano-rugiero@myseneca.ca
// Date of completion: 11-23-18
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>

class Utilities {
    
    size_t m_widthField = 1;
    static char m_delimiter;
   
    
    
public:
   
    void setFieldWidth(size_t width);
    size_t getFieldWidth() const;
    const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
    static void setDelimiter(const char);
    const char getDelimiter() const;
  
};

#endif /* UTILITIES_H */
