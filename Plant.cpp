// File: Plant.cpp
// 
// Contains the function definitions for the power Plant class
#include "Plant.h"

//
//  Constructors and Destructors
//
Plant::Plant(const string& name, const string& type, int voltage, double capacity, double availCapacity)
    : name(name), type(type), voltage(voltage), maxCapacity(capacity), availCapacity(availCapacity) {
}


//
// isOperational(): - Boolean if plant is operational or not
//
bool Plant::isOperational() const {
    return availCapacity > 0;
}

//
// reduceCapacity() - reduces available capacity of a plant 
void Plant::reduceCapacity(double amount) {
    assert(amount <= availCapacity);

    if (amount <= availCapacity) {
        availCapacity -= amount;
    }
}


// Getters and Setters
string Plant::getName() const { return name; }
string Plant::getType() const { return type; }
int Plant::getVoltage() const { return voltage; }
double Plant::getMaxCapacity() const { return maxCapacity; }
double Plant::getAvailCapacity() const { return availCapacity; }


// Debug and Print functions
void Plant::printAll() const {
    cout << this <<
        "  Plant: " << setw(14) << left << name <<
        setw(12) << left << type <<
        setw(10) << right << voltage << "kv" <<
        setw(10) << right << maxCapacity << "mw" <<
        setw(10) << right << availCapacity << "mw" << endl;
}
