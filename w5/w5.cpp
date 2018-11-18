// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22

#include <iostream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {
    
    std::cout << "Command Line: ";
    for (int i = 0; i < argc; i++)
        std::cout << argv[i] << ' ';
    std::cout << std::endl;
    
    if (argc == 1) {
        std::cerr << "\n*** Insufficient number of arguments ***\n";
        std::cerr << "Usage: " << argv[0] << " fileName \n";
        return 1;
    }
    else if (argc != 2) {
        std::cerr << "\n*** Too many arguments ***\n";
        std::cerr << "Usage: " << argv[0] << " fileName \n";
        return 2;
    }
    sict::Grades grades(argv[1]);
    //TODO: Update the main functions as per the specifications here
    auto letter = [](double grades)->string
    {
        
        Letter letterObj;
        
        if (grades >= 90)
            letterObj = AA;
        else if (grades >= 80)
            letterObj = A;
        else if (grades >= 75)
            letterObj = BB;
        else if (grades >= 70)
            letterObj = B;
        else if (grades >= 65)
            letterObj = CC;
        else if (grades >= 60)
            letterObj = C;
        else if (grades >= 55)
            letterObj = DD;
        else if (grades >= 50)
            letterObj = D;
        else
            letterObj = F;
        
        return convertToString(letterObj);
    };
    
    grades.displayGrades(std::cout, letter);
    
    return 0;
}
