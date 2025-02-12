#pragma once
// File: PowerGrid.h
//
// Contains class definition for the overall PowerGrid Object class
// 
// The PowerGrid class contains support, analysis, and modeling attribues 
// for the overall Grid
//
#include <vector>
#include <string>

#include "Plant.h"
#include "Demand.h"
#include "TransLine.h"

//
// Class PowerGrid
//
// This class is an aggregation of all the Plants, Demand Locations, and
// Transmission Lines if the power Grid.   The information for each instance
// of these is stored in a vector in this class.
// 
// The class has functions to read a data file, add an instance to the grid,
// and print the components in the grid.
// 
// The class also has support and action function(s) includeiing:
//  1) Run a balancing routine to distribute power from the plants to
//     the locations over the transmission lines and track enrgy loss.
// 
//  2) Print a report of the distribution and effciency.
// 
class PowerGrid {
public:

    // Vectors containing instances of plants, demands, and transmission lines
    vector<Plant>     plants;
    vector<Demand>    demands;
    vector<TransLine> transLines;

public:
    // Functions to read, manage, and print power plants
    void readPlantData(const string& filename);
    void addPlant(const Plant& plant);
    void printPlants(ostream& out) const;

    // Functions to read, manage, and print power demand locations
    void readDemandData(const string& filename);
    void addDemand(const Demand& demand);
    void printDemands(ostream& out) const;

    // Functions to read, manage, and print the transmison lines
    void readTransLineData(const string& filename);
    void addTransLine(const TransLine& transLine);
    void printTransLines(ostream& out) const;

    // Functions to distribute power : in file DistPower.cpp
    void distributePower(ostream& out);                         // Distributes power to all demand locations
    void allocateToDemand(Demand& demand, ostream& out);          // Allocates power and line capacity to a demand location
    void generateUsageReport(string companyName, ostream& out);   // Generates a power report to the console

};

