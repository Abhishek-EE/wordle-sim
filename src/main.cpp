#include "engine/wordle_engine.h"
#include "solver/random_solver.h"
#include "simulator/simulator.h"
#include <iostream>

int main() {
    using namespace wordle;

    std::cout << "Wordle Simulation starting...\n";

    engine::WordleEngine engine("apple");
    solver::RandomSolver solver;
    simulator::Simulator sim;

    try {
        sim.run(engine, solver);
    } catch (const std::logic_error& e) {
        std::cerr << "Not yet implemented: " << e.what() << "\n";
    }

    return 0;
}
