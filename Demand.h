#pragma once
// File: Demand.h
//
// Contains class definition for the Demand class on the power grid
//
// Demand objects identify a location and a the amount of power (megawatts) 
// that the location requires.  
// 
// They track how much power is currently being supplied and the amount 
// needed to fully to meet their power requirements.  They can also 
// quickly report on the status of if their requiermends are satisfied.
// 
#include <string>
using namespace std;

class Demand {
 private:
    string  location;
    double     requiredCapacity;
    double     suppliedCapacity;
    string  status;

public:
    // Consructors & Destructors
    Demand(const string& name, double requiredCapacity);

    // Mutators
    void addCapacity(double amount);

    // Accesors
    string getLocation() const;
    double getRequiredCapacity() const;
    double getSuppliedCapacity() const;
    string getStatus() const;

    // Print and debug
    void printAll() const;   // Prints information for debugging
};


