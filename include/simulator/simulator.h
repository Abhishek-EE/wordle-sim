#pragma once

#include "engine/wordle_engine.h"
#include "solver/solver.h"
#include <stdexcept>
#include <string>

namespace wordle {
namespace simulator {

class Simulator {
public:
    Simulator() = default;

    // Run a game with given engine + solver
    void run(wordle::engine::WordleEngine& engine, wordle::solver::Solver& solver) {
        throw std::logic_error("TODO: Implement Simulator::run");
    }
};

} // namespace simulator
} // namespace wordle
