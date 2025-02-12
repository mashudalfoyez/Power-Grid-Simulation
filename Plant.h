#pragma once
// File: Plant.h
//
// Contains class definition for the power Plant class
//
// Plants generate the electricity and supply it to demand location 
// using transmission lines.
//
// Plants have varying characteriscs such as Fuel Type, Capacity, Age, 
// cost to produce electricty, hours of operation, and environmental 
// impact.
//
// Plants understand their total capacity and track how much power
// has already been committed and the amount available to provide.
// 

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cassert>
using namespace std;

class Plant {
 private:
    string  name;
    string  type;
    int     voltage;
    double  maxCapacity;
    double  availCapacity;

public:
    // Consructors & Destructors
    Plant(const string& name, const string& type, int voltage, double maxCapacity, double availCapacity);

    // Mutators
    bool isOperational() const;
    void reduceCapacity(double amount);

    // Accessors
    string getName() const;
    string getType() const;
    int getVoltage() const;
    double getMaxCapacity() const;
    double getAvailCapacity() const;

    // Print and debug 
    void printAll() const;

};
