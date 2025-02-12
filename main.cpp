/** Author: Mashud Alfoyez* 
Creation Date : < 01 - 31 - 2025 >
Last Modification Date : < 02 - 10 - 2025 >
Purpose : Inheritance, virtual functions, and abstract classes.
*/


// File:  main.cpp
//
// This file contains the main() for the CIS200 W25 Power Grid assignment
// 
// It instantiates a PowerGrid type called myGrid.  The grid reads data
// files containing configurations of Plants, Demand locations, 
// and transmission lines.  The plants, demands, and lines have varying
// levels of capacity, need, and efficiencies.
//
// The grid then calls a function to distribute the energy from the plants
// to the demand locations using the transmission lines.  All of the data
// is received in a sorted order and the distribution follows a simple
// algorithm.
//
// After the distribution, a well formatted report is produced showing
// various usage and efficiency characteristics of the power grid.
// 
// This project was designed by Richard Frost - UMich Dearborn W2025.
// Please contact for permission to reuse!
//

#include "PowerGrid.h"
#include <iostream>
using namespace std;

// Filenames and/or Location Constants
const string PLANTS_FILE = "A1_Plants.txt";
const string DEMANDS_FILE = "A1_Demands.txt";
const string TRANSLINES_FILE = "A1_TransLines.txt";
const string REPORT_FILE = "A1_Report.txt";

// Name of company that owns the power grid
const string GRID_NAME = "Rich's Amazing Energy Grid";


//
// main():  Main function for Power Grid project
//
int main() {
    PowerGrid myGrid;
    ofstream outFile(REPORT_FILE);
    if (!outFile) {
        cerr << "Error: Unable to open file " << REPORT_FILE << " for writing." << endl;
        return 1;
    }

    // Read and display Plant information.
    myGrid.readPlantData(PLANTS_FILE);
    outFile << "\t\t--- Initial Plant Summary ---\n";
    myGrid.printPlants(outFile);


    // Read and display Demand information.
    myGrid.readDemandData(DEMANDS_FILE);
    outFile << "\n\n\t--- Initial Demand Summary ---\n";
    myGrid.printDemands(outFile);


    // Read and display Transmission Line information.
    myGrid.readTransLineData(TRANSLINES_FILE);
    outFile << "\n\n\t--- Initial Transmission Line Summary ---\n";
    myGrid.printTransLines(outFile);
    
    
    // Distribute power from plants to all demand locations
    outFile << "\n\t--- Allocating power to the demand locations ---\n";
    myGrid.distributePower(outFile);

    
    // Generate report on usage and efficiency
    outFile << endl << endl;
    myGrid.generateUsageReport(GRID_NAME, outFile);
    outFile.close();
    cout << "Report generated successfully. Check " << REPORT_FILE << " for details." << endl;


    return 0;
}
