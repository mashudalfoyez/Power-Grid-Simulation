// File: Demand.cpp
// 
// Contains the function definitions for the power grid Demand class
//
#include "Demand.h"
#include <iostream>
#include <iomanip>


//
//  Constructors and Destructors
//
Demand::Demand(const string& name, double requiredCapacity)
    : location(name), requiredCapacity(requiredCapacity), suppliedCapacity(0), status("Not Met") {
}


//
// Adds capacity to the demand location 
//
void Demand::addCapacity(double amount) {

    // Add the amount being supplied and update demand status 
    suppliedCapacity += amount;

    if (suppliedCapacity >= requiredCapacity)
        status = "Met";
    else if (suppliedCapacity > 0)
        status = "Partially Met";
    else
        status = "Not Met";
}


//
// Setters and Getters
//
string Demand::getLocation() const { return location; }
double Demand::getRequiredCapacity() const { return requiredCapacity; }
double Demand::getSuppliedCapacity() const { return suppliedCapacity; }
string Demand::getStatus() const { return status; }


// Debug and Print functions
void Demand::printAll() const {
    cout << this <<
        "  Demand Location: " << setw(12) << left << location <<
        setw(8) << right << requiredCapacity <<
        setw(8) << right << suppliedCapacity <<
        setw(12) << right << status << endl;
}
