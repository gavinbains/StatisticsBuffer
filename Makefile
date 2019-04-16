# Set up compiler and necessary flags for compilations
CXX = g++
CPPFLAGS = -g -Wall -std=c++11

all: main

# Compile the executable
main: DataContainer.o StatisticsBuffer.o main.cpp
	$(CXX) $(CPPFLAGS) DataContainer.o StatisticsBuffer.o main.cpp -o main

# Compile the StatisticsBuffer class into an object file
StatisticsBuffer.o: StatisticsBuffer.h StatisticsBuffer.cpp
	$(CXX) $(CPPFLAGS) StatisticsBuffer.cpp -c -o StatisticsBuffer.o

# Compile the DataContainer class into an object file
DataContainer.o: DataContainer.h DataContainer.cpp
	$(CXX) $(CPPFLAGS) DataContainer.cpp -c -o DataContainer.o

# Handle cleaning the directory
.PHONY: clean

clean:
	rm DataContainer.o
	rm StatisticsBuffer.o
	rm main.exe


