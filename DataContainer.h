//
// Created by gbains on 2/13/2019.
//

#ifndef DATACONTAINER_H
#define DATACONTAINER_H

#include <array>

template <size_t T_width>
class DataContainer : public std::array<double, T_width>{
public:
    // Constructor
    DataContainer<T_width>();
    // Fills DataContainer with values
    template<class T>
    void fill(T);
    // Raise each element in DataContainer to power d
    template<class T>
    DataContainer<T_width> Pow(T d);
    // SquareRoot each element in DataContainer
    DataContainer<T_width> Sqrt();
    // Overloaded operators to perform elementwise operations
    template<class T>
    DataContainer<T_width> operator/(T);
    DataContainer<T_width> operator+(DataContainer &other);
    DataContainer<T_width> operator-(DataContainer &other);
    // Compound assignments
    void operator+=(DataContainer &other);
    void operator-=(DataContainer &other);
    // Utility to print for debugging
    void print();
};


#endif
