// File: PowerGrid.cpp
// 
// Contains the function code for the overal PowerGrid class
// 
// This class contains the plants, demands, and lines of the grid and
// this file contains member functions for reading, inserting, and 
// printing the key components of the grid.

#include "PowerGrid.h"
using namespace std;


//********************************************************
//*****        Functions for Power Plants            *****
//********************************************************

//
//  readPlantData():   Reads the information about each plant from the data
//                  file and adds them to the grid
//
void PowerGrid::readPlantData(const string& plantFilename) {

    // Variables used to read demand info from file
    string name, type;
    int voltage, capacity;

    // Open data file for reading
    ifstream isPlant(plantFilename);
    if (!isPlant) {
        cerr << "Error: Unable to open file " << plantFilename << endl;
        return;
    }

    // Read the first plant record
    isPlant >> name >> type >> voltage >> capacity;

    // Process all reords in the file 
    while (!isPlant.eof() && !isPlant.fail()) {

        // Add the plant to the grid with max capacity the same as capacity
        Plant newPlant(name, type, voltage, capacity, capacity);
        //newPlant.printAll();    // Display information to screen before adding 
        addPlant(newPlant);

        // Read next record
        isPlant >> name >> type >> voltage >> capacity;
    }

    isPlant.close();
}


//
// addPlant()
//
void PowerGrid::addPlant(const Plant& plant) {
    plants.push_back(plant);
}


//
// printPlants()
//
void PowerGrid::printPlants(ostream& out) const {
    // Print column headings
    out << "  Plant         Type       Voltage   Max Cap  Availabe\n";
    out << "---------     --------     -------   -------  --------\n";

    // Loop and print all information for each Plant.
    for (const auto& plant : plants) {
        out <<
            setw(14) << left << plant.getName() <<
            setw(10) << left << plant.getType() <<
            setw(8) << right << plant.getVoltage() << "kv" <<
            setw(8) << right << plant.getMaxCapacity() << "mw" <<
            setw(8) << right << plant.getAvailCapacity() << "mw" << endl;
    }
}


//********************************************************
//*****          Functions for Demands               *****
//********************************************************

//
//  readDemandData():   Reads the information about each demand from the data
//                  file and adds them to the grid
//
void PowerGrid::readDemandData(const string& demandFilename) {

    // Variables used to read demand info from file
    string  location;
    int     requiredCapacity;
    string  status;

    // Open data file for reading
    ifstream isDemand(demandFilename);
    if (!isDemand) {
        cerr << "Error: Unable to open file " << demandFilename << endl;
        return;
    }

    // Read the first demand record
    isDemand >> location >> requiredCapacity;

    // Process all reords in the file 
    while (!isDemand.eof() && !isDemand.fail()) {

        // Add the demand to the grid with max capacity the same as capacity
        Demand newDemand(location, requiredCapacity);
        // newDemand.printAll();   // Display information to screen before adding 
        addDemand(newDemand);

        // Read next record
        isDemand >> location >> requiredCapacity;
    }

    isDemand.close();
}


//
// addDemand()
//
void PowerGrid::addDemand(const Demand& demand) {
    demands.push_back(demand);
}


//
// printDemands()
//
void PowerGrid::printDemands(ostream& out) const {
    // Print column headings
    out << " Location      Demand     Supplied     Status\n";
    out << "----------    --------    --------    --------\n";

    // Loop and print all information for each demand.
    for (const auto& demand : demands) {
        out <<
            setw(14) << left << demand.getLocation() <<
            setw(8) << right << demand.getRequiredCapacity() <<
            setw(12) << right << demand.getSuppliedCapacity() <<
            setw(12) << right << demand.getStatus() << endl;
    }
}



//********************************************************
//*****      Functions for Transmission Lnes         *****
//********************************************************

//
//  readTransLineData():   Reads the information about each transLine 
//              from the data file and adds them to the grid
//
void PowerGrid::readTransLineData(const string& transLineFilename) {

    // Variables used to read transLine info from file
    string  lineID;
    int     capacity;
    double  efficiency;

    ifstream isTransLine(transLineFilename);
    if (!isTransLine) {
        cerr << "Error" << transLineFilename << endl;
        return;
    }
    isTransLine >> lineID >> capacity >> efficiency;

    while (!isTransLine.eof() && !isTransLine.fail()) {
        TransLine newTransLine(lineID, capacity, efficiency);
        addTransLine(newTransLine);
        isTransLine >> lineID >> capacity >> efficiency;
    }
    isTransLine.close();
}


//
// addTransLine()
//
void PowerGrid::addTransLine(const TransLine& transLine) {
    transLines.push_back(transLine);
}


//
// printTransLines()
//
void PowerGrid::printTransLines(ostream& out) const {
    out << "Line ID | Capacity | Efficiency"<<endl;
    out << "--------  ---------  ---------"<<endl;

    for (const auto& transLine : transLines) {
        out << setw(10) << left << transLine.getLineID()
            << setw(8) << right << transLine.getCapacity()
            << setw(12) << right << transLine.getEfficiency() << endl;
    }
}