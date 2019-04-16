//
// Created by gbains on 2/13/2019.
//

#include "DataContainer.h"
#include <iostream>
#include <cmath>


/**
 * Constructor for DataContainer
 *
 * @tparam T_width represents the length of the DataContainer
 */
template <size_t T_width>
DataContainer<T_width>::DataContainer() = default;

/**
 * Fills the array with the value given in the parameter
 *
 * @tparam T_width  represents the length of the DataContainer
 * @tparam T Represents type of element to fill the array with, should be int or double
 * @param d the element to fill array with
 */
template<size_t T_width>
template<class T>
void DataContainer<T_width>::fill(T d) {
    for (int i = 0; i < T_width; ++i) {
        (*this)[i] = d;
    }
}

/**
 * Overloading of addition operator to perform elementwise operation on the DataContainers
 *
 * @tparam T_width
 * @param other
 * @return result that is the new DataContainer
 */
template<size_t T_width>
DataContainer<T_width> DataContainer<T_width>::operator+(DataContainer &other) {
    DataContainer<T_width> result;
    for (int i = 0; i < T_width; ++i) {
        result[i] = (*this)[i] + other[i];
    }
    return result;
}

/**
 * Overloading of subtraction operator to perform elementwise operation on the DataContainers
 *
 * @tparam T_width
 * @param other
 * @return
 */
template<size_t T_width>
DataContainer<T_width> DataContainer<T_width>::operator-(DataContainer &other) {
    DataContainer<T_width> result;
    for (int i = 0; i < T_width; ++i) {
        result[i] = (*this)[i] - other[i];
    }
    return result;
}

/**
 * Overloading of division operator to perform elementwise division by any number
 *
 * @tparam T_width
 * @tparam T
 * @param d
 * @return
 */
template<size_t T_width>
template<class T>
DataContainer<T_width> DataContainer<T_width>::operator/(T d) {
    DataContainer<T_width> result;
    for (int i = 0; i < T_width; ++i) {
        result[i] = (*this)[i] / d;
    }
    return result;
}

/**
 * Utility function to print the contents of the DataContainer for debugging
 *
 * @tparam T_width
 */
template<size_t T_width>
void DataContainer<T_width>::print() {
    for (int i = 0; i < T_width; ++i) {
        std::cout << (*this)[i] << std::endl;
    }
}

/**
 * Compound assignments
 *
 * @tparam T_width
 * @param other
 */
template<size_t T_width>
void DataContainer<T_width>::operator+=(DataContainer &other) {
    for (int i = 0; i < T_width; ++i) {
        (*this)[i] = (*this)[i] + other[i];
    }
}

/**
 * Compound assignments
 *
 * @tparam T_width
 * @param other
 */
template<size_t T_width>
void DataContainer<T_width>::operator-=(DataContainer &other) {
    for (int i = 0; i < T_width; ++i) {
        (*this)[i] = (*this)[i] - other[i];
    }
}

/**
 * Raise each element to the power of the parameter provided
 *
 * @tparam T_width
 * @tparam T
 * @param d
 * @return
 */
template<size_t T_width>
template<class T>
DataContainer<T_width> DataContainer<T_width>::Pow(T d) {
    DataContainer<T_width> result;
    for (int i = 0; i < T_width; ++i) {
        result[i] = pow((*this)[i], d);
    }
    return result;
}

/**
 * Squareroot each element in the DataContainer
 *
 * @tparam T_width
 * @return
 */
template<size_t T_width>
DataContainer<T_width> DataContainer<T_width>::Sqrt() {
    DataContainer<T_width> result;
    for (int i = 0; i < T_width; ++i) {
        result[i] = sqrt((*this)[i]);
    }
    return result;
}
