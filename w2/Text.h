// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email: cmoyano-rugiero@myseneca.ca
// Date of completion: 09-20-18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W2_TEXT_H
#define W2_TEXT_H



namespace w2{
    
    class Text {
        
    private:
        
        std::string * _text;
        std::string _fileName;
        size_t _numberOfLines;
        
        
    public:
        Text(); //default constructor with no parameters
        Text(const char * fileName);  // constructor
        Text(const Text& src);  //copy contructor
        Text& operator=(const Text& src); // copy assigment operator
        Text(Text&& src); // move contructor
        Text& operator=(Text&& src); // move assigment operator
        ~Text(); // destructor
        size_t size() const; // return number of records of text data
        void countLines();  // member function to count lines of file
        void storeRecords(); // member function to store records of file

    };
}


#endif /* W2_TEXT_H */
