# Wordle Simulator

A modular **C++ Wordle simulation framework**.  
It includes the **Wordle game engine** (implemented) and scaffolds for a **dictionary**, **solvers**, and a **simulator**.  

The project is built with **CMake** and tested using **GoogleTest**. 

## 🚀 Features

✅ **Implemented**
- Wordle Engine (case-insensitive word comparison, feedback with `G`, `Y`, `B`)  
- Utils (string lowercase conversion)  

🟡 **TODO (scaffolds provided)**
- Dictionary (load words, random word selection)  
- Random Solver (guesses randomly from dictionary)  
- Frequency Solver (guesses based on letter frequency)  
- Simulator (runs full Wordle games using engine + solver)  

---

## 🛠️ Build Instructions

### 1. Clone and configure
```bash
git clone https://github.com/your-username/wordle-sim.git
cd wordle-sim
mkdir build && cd build
cmake ..
make -j

# play wordle in cli
./wordle_cli

# Run Simulator (When implemented)
./wordle_sim

# Run Tests
ctest
```

## 📌 Notes

- By design, the game engine is case-insensitive.
- Other modules (dictionary, solvers, simulator) are currently scaffolds and throw std::logic_error("Not implemented") if used.
- See TODO comments in the code to implement missing functionality.