⚡ Power Grid Simulation ⚡

The Power Grid Simulation models an electric power grid to analyze power generation, transmission, and distribution efficiency. This project integrates Object-Oriented Programming (OOP) principles such as inheritance, composition, and friend functions, while utilizing file I/O for data handling and report generation.

🚀 Features:
✅ Models power plants, transmission lines, and demand points✅ Allocates power based on capacity & efficiency✅ Accounts for efficiency losses during transmission✅ Generates a detailed performance report

🎯 Learning Objectives:
1️⃣ Implement class definitions & function implementations using .h and .cpp files.
2️⃣ Apply OOP principles, including inheritance & composition.
3️⃣ Perform file I/O operations for data handling.
4️⃣ Simulate power distribution & efficiency calculations.
5️⃣ Develop a structured approach to solving engineering problems using C++.

🏛️ Project Structure:
🏭 Plant Class: Represents power plants with attributes like name, type, voltage, and capacity.
🔗 TransLine Class: Models transmission lines with attributes such as efficiency & length.
🏙️ Demand Class: Represents cities or industries with specific power requirements.
⚡ PowerGrid Class: Manages power allocation from plants to demand points through transmission lines.
🤝 Friend Functions: Used to check power feasibility considering efficiency losses.


🔢 Power Allocation Algorithm:
1️⃣ 📂 Input Handling: Reads & processes plant, transmission line, and demand data from input files.
2️⃣ ⚖️ Matching & Allocation: Prioritizes highest demand points first, selects the most efficient transmission line, and updates demand fulfillment status.
3️⃣ 📊 Efficiency Calculation: Uses the formula:
🔹 Effective Power = Supplied Power × Efficiency
4️⃣ 📜 Report Generation: Summarizes demand fulfillment, total power supplied, and grid efficiency.

📂 Input Files:

📄 A1_Plants.txt: Contains plant data (name, type, voltage, capacity).
📄 A1_Demands.txt: Lists demand locations and their required power.
📄 A1_TransLines.txt: Details transmission lines with efficiency ratings.
