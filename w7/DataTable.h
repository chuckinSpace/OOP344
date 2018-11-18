// Name: Carlos Moyano
// Seneca Student ID: 123435174
// Seneca email: cmoyano-rugiero@seneca.ca
// Date of completion:10-9-18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W7_DATATABLE_H
#define W7_DATATABLE_H

#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <functional>
#include <iomanip>
#include <cmath>

namespace w7 {
    template<class T>
    class DataTable {
        
        
        int _fieldWidth;
        int _numbOfDecimals;
        std::vector<T> x;
        std::vector<T> y;
        
    public:
       
        DataTable(){}
        DataTable(std::ifstream& myFile, const int width, const int dec)
        {
            T temp_x;
            T temp_y;
            
            _fieldWidth = width;
            _numbOfDecimals = dec;
            
            if(myFile.is_open())
            {
                while(myFile >> temp_x >> temp_y)
                {
                    x.push_back(temp_x);
                    y.push_back(temp_y);
                }
            }
        }
        T mean() const
        {
            return std::accumulate(y.begin(), y.end(), 0.0) / y.size();
            
        }
        T sigma() const
        {
            T _mean = mean();
            std::vector<T> temp(y.size());
          
            
            
            std::transform(y.begin(),y.end(),temp.begin(), [&](T element){
                
                T result1 = pow((element - _mean),2);
                
                return result1;
             
              
            });
            
            T sumY = std::accumulate(temp.begin(), temp.end(), 0.0);
            return std::sqrt(sumY / (temp.size() - 1));
        }
        
        T median() const
        {
            std::vector<T> temp = y;
            sort(temp.begin(), temp.end());
            T index = temp[temp.size() / 2];
            return index;
        }
        
        void regression(T& slope, T& y_intercept) const
        {
          
            T sumX = std::accumulate(x.begin(), x.end(), 0.0);
            T sumY = std::accumulate(y.begin(), y.end(), 0.0);
            T numerator = x.size() * std::inner_product(x.begin(), x.end(), y.begin(), 0.0) - (sumX * sumY);
            T denominator = (x.size() * std::inner_product(x.begin(), x.end(), x.begin(), 0.0)) - pow(sumX,2);
            
            slope = numerator / denominator;
            y_intercept = (sumY - slope * sumX) / x.size();
        }
        void display(std::ostream& os) const{
            os << std::setw(_fieldWidth)
               << "x"
               << std::setw(_fieldWidth)
               << "y" << std::endl;
            for(size_t i = 0; i < x.size(); ++i)
            {
                os << std::fixed << std::setw(_fieldWidth) << std::setprecision(_numbOfDecimals)
                   << x[i]
                   << std::setprecision(_numbOfDecimals) << std::setw(_fieldWidth)
                   << y[i]
                   << std::endl;
            }
        }
        
        size_t getSize() const{ return x.size();}
        
    };
    template<class T>
    std::ostream& operator<<(std::ostream& os, const DataTable<T>& dataTable)
    {
        dataTable.display(os);
        return os;
    }

}

#endif /* DATATABLE_H */
