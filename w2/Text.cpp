// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email: cmoyano-rugiero@myseneca.ca
// Date of completion: 09-20-18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <fstream>
#include <string>
#include "Text.h"

using namespace std;

namespace w2{
    
    Text::Text(){
        _numberOfLines = 0;
        _text = nullptr;
    }
    
    Text::Text(const char * fileName){
        
        if(fileName){
            _fileName = fileName;
            countLines();       // funtion to count lines
            storeRecords();     // calling function to store records
        }else{
            _text = nullptr;
        }
    }
    
    void Text::countLines(){
        
        ifstream theFile(_fileName);
        string line;
        
        if(theFile.is_open()){
            while(getline(theFile,line)){
                this->_numberOfLines++;    //reading the number of records from file
            }
        }
        theFile.close();
     }
    
    void Text::storeRecords(){
        
        string line;
        ifstream theFile(_fileName);
        int i = 0;
        delete [] _text;
        _text = new string[_numberOfLines];
        if(theFile.is_open()){
            while(getline(theFile,line)){
                _text[i] = line;    //storing records from file
                i++;
            }
        }
        
        theFile.close();
        
    }
    
   // copy contructor
    Text::Text(const Text& src){
       *this = src;  // copying by calling assigment operator
    }
    
    // assigment operator
    Text& Text::operator=(const Text& src){
        if(this != &src){
            _numberOfLines = src._numberOfLines;
            delete [] _text;
            this->_text = new string [_numberOfLines];
            for(size_t i = 0; i < _numberOfLines; ++i){
                _text[i] = src._text[i];
            }
        }
        return *this;
    }
    // move contructor
    Text::Text(Text&& src){
        
        *this = move(src);  
        
    }
    // move assigment operator
    Text& Text::operator=(Text&& src){
        
        if(this != &src){
            delete [] this->_text;
            this->_text = src._text;
            this->_numberOfLines = src._numberOfLines;
            src._text = nullptr;
        }
        return *this;
    }
    Text::~Text(){
        delete [] _text;
        _text = nullptr;
    }
    size_t Text::size() const{
        
        return _numberOfLines;
    
    }
    
}
