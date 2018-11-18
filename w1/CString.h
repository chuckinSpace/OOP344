// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email:  cmoyano-rugiero@myseneca.ca
// Date of completion: 11-9-18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef CString_h
#define CString_h



namespace w1{

    const int MAX = 3;    // number of characthers to read
    
    class Cstring{
        
    private:
        char myChar[MAX+1];
        
    public:
        Cstring( const char* mystring);    //constructor
        void display(std::ostream& os) const;
        
        
    };
    std::ostream &operator<<(std::ostream &os, const Cstring &mystring);  //overloading our << with a non friend to display our CString object
}


#endif /* CString_h */
