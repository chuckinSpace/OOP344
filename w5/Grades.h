// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email: cmoyano-rugiero@myseneca.ca
// Date of completion: 10-12-2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef Grades_hpp
#define Grades_hpp

#include <iostream>
#include <iomanip>
#include "Letter.h"

using namespace std;

namespace sict {
    
    class Grades {
        
        
        std::string* _studentNumber;
        double* _grade;
        int _lines;
        
    public:
        Grades();
        Grades(const Grades& src) = delete;
        Grades& operator=(const Grades& src) = delete;
        Grades(Grades&& mvsrc) = delete;
        Grades&& operator=(Grades&& mvsrc)= delete;
        
        Grades(string filename);
        
        template<typename T>
        void displayGrades(std::ostream& os, T F) const
        {
            
            for(int i = 0 ; i < _lines ; ++i)
            {
                os << right << setw(10) << _studentNumber[i] << left << " " << fixed << setprecision(2) << setw(5)
                   << _grade[i] << " " << setw(4) << F(_grade[i]) << endl;
              
                
            }
        }
    };
    
}
#endif /* Grades_h */
