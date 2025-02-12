#pragma once
// File: TransLine.h
//
// Contains class definition for the Transmission Lines that connect 
// the power plants to demand locations
//
// The transmission lines connect the power plants to the demand locations.
//		Each line has a lineID, a capacity, and an efficiency.
// 
// The Capacity is maximum amount of power that can travel on the line. 
// The Efficiency models the engery lost connecting a plant to the demand.
//
#include <string>
using namespace std;

class TransLine {
public:
    string  lineID;
    int     capacity;
    double  efficiency;

public:
    TransLine(const string& lineID, int capacity, double efficiency);
    int getCapacity() const;
    double getEfficiency() const;
    string getLineID() const;

    void printAll() const;
};


