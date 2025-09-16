#pragma once

#include "solver/solver.h"
#include <stdexcept>

namespace wordle {
namespace solver {

class RandomSolver : public Solver {
public:
    RandomSolver() = default;

    std::string next_guess() override {
        throw std::logic_error("TODO: Implement RandomSolver::next_guess");
    }

    void feedback(const std::string&, const std::string&) override {
        // TODO: Record feedback to refine guesses
        throw std::logic_error("TODO: Implement RandomSolver::feedback");
    }
};

} // namespace solver
} // namespace wordle
