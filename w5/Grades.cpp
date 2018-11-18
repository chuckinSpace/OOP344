//// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email: cmoyano-rugiero@myseneca.ca
// Date of completion: 10-12-2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <fstream>
#include "Grades.h"

namespace sict {
    
    Grades::Grades(){
        
        _studentNumber =nullptr;
        _grade = nullptr;
        _lines = 0;
        
    }
    
    Grades::Grades(string filename) :  _studentNumber(nullptr), _grade (nullptr),_lines(0)
    {
        try{
            ifstream my_File(filename);
            string line;
            if (my_File.is_open()){
                
                while (getline(my_File, line)) {
                    _lines++;
                }
                my_File.clear();
                my_File.seekg(0);
                
               
                _studentNumber = new string[_lines];
                _grade = new double[_lines];
                
                for (int i = 0; i < _lines; i++) {
                    my_File >> _studentNumber[i];
                    my_File >> _grade[i];
                }
                my_File.close();
            }else{
                throw "Cannot open file" ;
            }
            
        
        }catch (const char* msg){
        cerr << msg << endl;
        exit(0);
    }
    
    }
}
