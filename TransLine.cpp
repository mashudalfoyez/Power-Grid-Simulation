// File: TransLine.cpp
// 
// Contains the function definitions for the power grid Transmission Line class
//
// The transmission lines connect the power plants to the demand locations.
//		Each line has a name, a capacity, and an efficiency.
// 
// The capacity is maximum amount of power that can travel on the line. 
// 
// The Efficiency has to do with power loss.  As power travels on a line, a 
// certain amount energy is lost. This energy loss is modeled by the efficiency
// of the line and has a number of contributing factors including:
// material, voltage, temperature,...
//
#include "TransLine.h"
#include <iostream>
#include <iomanip>


//
//  Constructors and Destructors
//
TransLine::TransLine(const string& lineID, int capacity, double efficiency)
    : lineID(lineID), capacity(capacity), efficiency(efficiency) {
}


//
// Setters and Getters
//
int TransLine::getCapacity() const { return capacity; }
double TransLine::getEfficiency() const { return efficiency; }
string TransLine::getLineID() const { return lineID; }

// Debug and Print functions
void TransLine::printAll() const {
    cout << this <<
        "  Line ID: " << setw(8) << left << lineID <<
        setw(8) << right << capacity <<
        setw(8) << right << efficiency << endl;
}
