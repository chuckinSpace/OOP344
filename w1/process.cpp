// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email:  cmoyano-rugiero@myseneca.ca
// Date of completion: 11-9-18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
//
#include <iostream>
#include "process.h"
#include "CString.h"





void process(const char* str, std::ostream& os) {
    w1::Cstring myString(str);
    std::cout << myString << std::endl;
}
