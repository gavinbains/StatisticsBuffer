//
// Created by gbains on 2/13/2019.
//

#include "StatisticsBuffer.h"
#include "DataContainer.h"


/**
 * Constructor for the StatisticsBuffer
 *
 * @tparam T_width
 */
template <size_t T_width>
StatisticsBuffer<T_width>::StatisticsBuffer(){
    means.fill(0);
    stddevs.fill(0);
};

template<size_t T_width>
StatisticsBuffer<T_width>::StatisticsBuffer(int len) {
    length = len;
}

/**
 * Everytime we add to the StatisticsBuffer we use the new DataContainer to reevaluate the mean and standard deviation
 * and check to be sure the size limits of the StatisticsBuffer are met
 *
 * @tparam T_width
 * @param dc
 */
template<size_t T_width>
void StatisticsBuffer<T_width>::add(DataContainer<T_width> dc) {
    // Initialize popped with zeroes
    DataContainer<T_width> popped;
    popped.fill(0);
    // PlusOne is whether an extra value is required for initial mean calculation
    int plusOne = 1;
    // Take size of the StatisticsBuffer
    int currSize = (*this).size();
    // Track whether StatisticsBuffer is full and required a pop
    bool isPopped = false;
    // If we need to pop
    if (getLength() == currSize){
        // Set popped to true
        isPopped = true;
        // No longer need an extra 1
        plusOne = 0;
        // Store popped DataContainer for future use
        popped = (*this).front();
        (*this).pop_front();
    }
    // Basic mean and stdDev calculation
    if(!isPopped) {
        for (int i = 0; i < T_width; ++i) {
            // Store original mean
            double oldMean = means[i];
            // Calculate new means and store them in the means DataContainer
            means[i] = (((currSize * oldMean) - popped[i]) + dc[i]) / (currSize + plusOne);
            // Calculate Standard Deviations and store
            double newSize = (double) currSize / (currSize + 1);
            double newValue = pow((double) dc[i] - oldMean, 2) / (currSize + 1);
            double currentVariance = pow(stddevs[i], 2);
            stddevs[i] = sqrt(newSize * (currentVariance + newValue));
        }
    }
    // If we StatisticsBuffer was full and we need to remove observation
    else{
        for (int i = 0; i < T_width; ++i) {
            // Standard mean calculation
            double oldMean = means[i];
            means[i] = ((((double)currSize * oldMean) - popped[i]) + dc[i]) / (currSize + plusOne);

            // Special formula to account for shift in data set
            double newSize = (pow((double)dc[i] - oldMean, 2) - pow((double)popped[i] - oldMean, 2))/(double)currSize;
            double secondTerm = pow((double)means[i] - oldMean, 2);
            double currentVariance = pow((double)stddevs[i], 2);
            stddevs[i] = sqrt(newSize + secondTerm + currentVariance);
        }
    }
    // Add the newest DataContainer to queue
    (*this).push_back(dc);
}

/**
 * Gets the maximum size limit of the StatisticsBuffer
 *
 * @tparam T_width
 * @return
 */
template<size_t T_width>
int StatisticsBuffer<T_width>::getLength() const {
    return length;
}

/**
 * Utility function to print values in the StatisticsBuffer for debugging
 *
 * @tparam T_width
 */
template<size_t T_width>
void StatisticsBuffer<T_width>::print() {
    for (int i = 0; i < T_width; ++i){
       // std::cout << means[i] << std::endl;
       std::cout << stddevs[i] << std::endl;
    }
}

/**
 * Setter for the size limit on the StatisticsBuffer
 *
 * @tparam T_width
 * @param length
 */
template<size_t T_width>
void StatisticsBuffer<T_width>::setLength(int length) {
    StatisticsBuffer::length = length;
}
