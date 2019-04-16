//
// Created by gbains on 2/13/2019.
//

#ifndef STATISTICSBUFFER_H
#define STATISTICSBUFFER_H

#include "DataContainer.h"
#include "DataContainer.cpp"
#include <queue>
#include <vector>

template <size_t T_width>
class StatisticsBuffer : public std::deque<DataContainer<T_width>>{
public:
    // Constructor
    StatisticsBuffer<T_width>();
    explicit StatisticsBuffer<T_width>(int len);
    // Add a DataContainer to the StatisticsBuffer
    void add(DataContainer<T_width>);
    // Return maximum length of StatisticsBuffer
    int getLength() const;
    // Utility to print and debug StatisticsBuffer
    void print();
    // Set maximum length of StatisticsBuffer
    void setLength(int length);

private:
    // Max length of StatisticsBuffer
    int length;
    // DataContainer for all of the means
    DataContainer<T_width> means;
    // DataContainer for all the Standard Deviations
    DataContainer<T_width> stddevs;
};


#endif //STATISTICSBUFFER_H
