// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email:  cmoyano-rugiero@myseneca.ca
// Date of completion: 11-9-18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include "process.h"

using namespace std;




int main(int argc, char* argv[])
{
 
    extern int STORED;      // linking STORED declared on .cpp to this unit
    
    cout << "Command Line: ";
    for (int i = 0; i < argc; i++)
    {
        cout << argv[i] << ' ';
    }
    if (argc < 2)
    {
        cout << "\nInsufficient number of arguments\n";
        return 1;
    }else{
        
        cout << endl << "Maximum number of characters stored: " << STORED << endl;
        
        for (int i = 1; i < argc; i++){
            
            process(argv[i],cout);
            
        }
    }
    
  
   
    
    return 0;
}
