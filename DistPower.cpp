// File: DistPower.cpp
// 
// Contains the functions for Power Distribution functions of the PowerGrid class
// 
// The functions implement the algorithms for analyzing demand, capacity, 
// grid topology, efficiency, and environmental impact to satisfy power
// demands.

#include "PowerGrid.h"
using namespace std;

//
// distributePower(): Distributes power to all demand locations
//
// This routine simply loops through each demand location, checks if
// has outstanding power requiemennts and calls the allocateToDemand 
// function to allocate power to it.
//
void PowerGrid::distributePower(ostream& out) {

    // Process the demand for each location
    for (auto& demand : demands) {

        // Check if this location has outstanding demand and allocate power to it
        if (demand.getRequiredCapacity() > 0) {
            allocateToDemand(demand, out);
        }
    }
}


//
// Allocates power and line capacity to a demand location
//
void PowerGrid::allocateToDemand(Demand& demand, ostream& out) {

    // Variables to track the remaining demand and the total supplied
    double remainingDemand = demand.getRequiredCapacity();

    // Try every line to supply power for the curent demand
    // Note: For assignment 1, a line always has capacity so this not really necessary 
    for (const auto& line : transLines) {

        // Move to the next line if this one does not have any capacity
        if (line.capacity <= 0.0)   continue;

        // Search the plants to see which plants have power to peovide
        for (auto& plant : plants) {
            if (plant.isOperational()) {
                double effectPower = (plant.getMaxCapacity() * line.getEfficiency());

                if (plant.isOperational()) {
                    // Calculate the effective power after transmission efficiency loss
                    double effectPower = (plant.getAvailCapacity() * line.getEfficiency());

                    // Check if the plant can fully or partially satisfy the remaining demand
                    if (effectPower >= remainingDemand) {
                        // Allocate the remaining demand
                        double allocPower = remainingDemand;
                        double suppPower = (remainingDemand / line.getEfficiency());
                        plant.reduceCapacity(suppPower);
                        demand.addCapacity(allocPower); // Use addCapacity to update suppliedCapacity and status
                        out << "Allocating: " << fixed << setprecision(2) << allocPower
                            << " for " << demand.getLocation()
                            << " Using: " << fixed << setprecision(2) << suppPower
                            << " From " << plant.getName()
                            << " On " << line.getLineID() << endl;
                        remainingDemand = 0; // Demand fully met
                        break; // Stop checking other plants
                    }
                    else if (effectPower > 0) {
                        // Allocate the available effective power
                        double allocPower = effectPower;
                        double suppPower = (effectPower / line.getEfficiency());
                        plant.reduceCapacity(suppPower);
                        demand.addCapacity(allocPower); // Use addCapacity to update suppliedCapacity and status

                        out << "Allocating: " << fixed << setprecision(2) << allocPower
                            << " for " << demand.getLocation()
                            << " Using: " << fixed << setprecision(2) << suppPower
                            << " From " << plant.getName()
                            << " On " << line.getLineID() << endl;

                        remainingDemand -= effectPower; // Reduce remaining demand
                    }
                }
            }
            // Stop checking other plants if the full demand is met
            if (remainingDemand <= 0) break;
        }

        // Stop checking other lines if the full demand is met
        if (remainingDemand <= 0) break;
    }
}


void PowerGrid::generateUsageReport(string companyName, ostream& out) {
    double totalDemandRequested = 0;
    double totalDemandSupplied = 0;

    // Print Headings
    out << "\t" << companyName << endl;
    out << "\t Grid Simulation Report" << endl;
    out << "Location   | Required(MW) | Supplied(MW) | Status" << endl;
    out << "------------------------------------------------" << endl;

    // Loop through Demands and print status of each demand location
    for (auto& demand : demands) {

        // Print out the demand inforamtion
         out << std::setw(10) << std::left << demand.getLocation() << " | "
            << std::setprecision(2) << std::setw(12) << std::right << demand.getRequiredCapacity() << " | "
            << std::setprecision(2) << std::setw(12) << std::right << demand.getSuppliedCapacity() << " | "
            << std::setw(10) << std::left << demand.getStatus()
            << endl;
        // Collect the total requested and supplied Demand
        totalDemandRequested += demand.getRequiredCapacity();
        totalDemandSupplied += demand.getSuppliedCapacity();
    }

    // Loop through the plants and total how much capacity was used.
    double totalPlantUsage = 0;
    for (auto& plant : plants) {
        totalPlantUsage += (plant.getMaxCapacity() - plant.getAvailCapacity());
    }

    out << endl << endl << "Overall Grid Performance:" << endl
     << "    Total Demand Request:  " << totalDemandRequested << " MW" << endl
     << "    Total Demand supplied: " << totalDemandSupplied << " MW" << endl
    << "    Percent of demand met: " << (totalDemandSupplied / totalDemandRequested) << "%" << endl
    << endl
    << "    Plant Capacity used:   " << totalPlantUsage << " MW" << endl
    << "    Efficiency percentage: " << (totalDemandSupplied / totalPlantUsage) << endl;

}