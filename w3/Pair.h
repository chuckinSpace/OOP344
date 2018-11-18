// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email: cmoyano-rugiero@myseneca.ca
// Date of completion: 9-25-18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
#ifndef PAIR_H
#define PAIR_H

#include <iostream>


template<typename A, typename B>
class Pair{
    
    A _storedKey;
    B _storedValue;
    
public:
    Pair();
    Pair(const A& key, const B& value);
    const A& getKey() const;
    const B& getValue() const;
    
};

template<typename A, typename B>
Pair<A,B>::Pair()
{
   _storedKey = '\0';
   _storedValue = 0.0;
}

template<typename A, typename B>
Pair<A,B>::Pair(const A& key, const B& value)
{
    _storedKey = key;
    _storedValue = value;    
}

template<typename A, typename B>
const A& Pair<A,B>::getKey() const
{
    return _storedKey;
}
template<typename A, typename B>
const B& Pair<A,B>::getValue() const
{
    return _storedValue;
}

#endif /* PAIR_H */


