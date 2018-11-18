// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email: cmoyano-rugiero@myseneca.ca
// Date of completion: 10-12-2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SICT_LETTER_H
#define SICT_LETTER_H

namespace sict {
    enum Letter { AA, A, BB, B, CC, C, DD, D, F };
    
    template<typename F>
    char* convertToString(const F& myEnumParam)
    {
        
        const char* myEnumChar;
        switch(myEnumParam){
            case Letter::AA : myEnumChar = "A+";
                          break;
            case Letter::A : myEnumChar = "A";
                break;
            case Letter::BB : myEnumChar = "B+";
                break;
            case Letter::B : myEnumChar = "B";
                break;
            case Letter::CC : myEnumChar = "C+";
                break;
            case Letter::C : myEnumChar = "C";
                break;
            case Letter::DD : myEnumChar = "D+";
                break;
            case Letter::D : myEnumChar = "D";
                break;
            case Letter::F : myEnumChar = "F";
                break;
            default : myEnumChar = "No Selection";
        }
        return const_cast<char*>(myEnumChar);
    }
}


#endif //!SICT_LETTER_H
