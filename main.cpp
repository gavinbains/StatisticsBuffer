#include <iostream>
// TODO: Figure out whether I need to remove the .h include here
#include "DataContainer.h"
#include "StatisticsBuffer.h"
#include "StatisticsBuffer.cpp"

using namespace std;

#define DATAROW_LENGTH 4

typedef DataContainer<DATAROW_LENGTH> DataRow;
typedef StatisticsBuffer<DATAROW_LENGTH> StatBuff;

int main(int argc, char** argv) {
    // Simple Tests for DataContainer
    DataRow d1,d2,d3,d4;
    StatBuff sb;
    sb.setLength(3);
    d1.fill(10);
    d2.fill(20);
    d3.fill(50);
    d1.print();
    d2.print();
    d3 = d1 + d2;
    d3.print();
    d3 = d1 - d2;
    d3.print();
    d3 = d1 / 5;
    d1.print();
    d3.print();
    d3 += d1;
    d3.print();
    d1.print();
    d3 -= d2;
    d3.print();
    d2.print();
    d3 = d1.Pow(2);
    d3.print();
    d1.print();
    d3 = d2.Sqrt();
    d3.print();
    d2.print();

    // Simple Tests for Statistics Buffer
    d1.fill(10);
    d2.fill(20);
    d3.fill(30);
    d4.fill(10);
    sb.add(d1);
    sb.print();
    sb.add(d2);
    sb.print();
    sb.add(d3);
    sb.print();
    sb.add(d4);
    sb.print();

    return 0;
}