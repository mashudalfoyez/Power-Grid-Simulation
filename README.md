Power Grid Simulation

Introduction

The Power Grid Simulation models an electric power grid to analyze power generation, transmission, and distribution efficiency. The simulation incorporates object-oriented programming principles such as inheritance, composition, and friend functions, while utilizing file I/O for data handling and report generation.

Features

Models power plants, transmission lines, and demand points.

Allocates power to demand points based on available capacity and efficiency.

Accounts for efficiency losses during transmission.

Generates a report summarizing power distribution and overall grid performance.

Learning Objectives

Implement class definitions and function implementations using separate .h and .cpp files.

Apply object-oriented principles, including inheritance and composition.

Perform file I/O operations for reading and writing data.

Simulate power distribution and efficiency calculations.

Develop a structured approach to solving engineering problems using C++.

Project Structure

Plant Class: Represents power plants with attributes like name, type, voltage, and capacity.

TransLine Class: Models transmission lines with attributes such as efficiency and length.

Demand Class: Represents cities or industries with specific power requirements.

PowerGrid Class: Manages the allocation of power from plants to demand points through transmission lines.

Friend Functions: Used to check power allocation feasibility considering efficiency losses.

Power Allocation Algorithm

Input Handling:

Read and process power plant, transmission line, and demand data from input files.

Ensure data is pre-sorted for efficient allocation.

Matching and Allocation:

Prioritize highest demand points first.

Select the most efficient available transmission line.

Allocate power while considering plant capacity and transmission losses.

Update demand fulfillment status as "Met," "Partially Met," or "Not Met."

Efficiency Calculation:

Compute effective power using the formula:

Effective Power = Supplied Power × Efficiency

Report Generation:

Summarizes demand fulfillment, total power supplied, and grid efficiency.

Input Files

A1_Plants.txt: Contains pre-sorted plant data with attributes such as name, type, voltage, and capacity.

A1_Demands.txt: Lists demand locations and their required power.

A1_TransLines.txt: Details transmission lines with efficiency ratings.
