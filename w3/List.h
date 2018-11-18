// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email: cmoyano-rugiero@myseneca.ca
// Date of completion: 9-25-18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef LIST_H
#define LIST_H

#include <iostream>

template<typename T, int N>
class List
{
    
    T _myarrayofanytype[N];
    int numberOfEntries;
    
    
public:
    
    List();
    size_t size() const;
    const T& operator[](int index) const;
    void operator +=(const T&);
    
};

template<typename T,int N>
List<T,N>::List() : _myarrayofanytype(), numberOfEntries(0)
{
   
}
template<typename T, int N>
size_t List<T,N>::size() const
{
    return numberOfEntries; //retunring N as the size?? not sure
}

template<typename T, int N>
void List<T,N>::operator +=(const T& newelement)
{
    _myarrayofanytype[numberOfEntries] = newelement;
    numberOfEntries++;
    
}
template<typename T, int N>
const T& List<T,N>::operator[](int index) const
{
    return _myarrayofanytype[index];
}
#endif /* LIST_H */
