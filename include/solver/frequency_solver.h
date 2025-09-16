#pragma once

#include "solver/solver.h"
#include <stdexcept>

namespace wordle {
namespace solver {

class FrequencySolver : public Solver {
public:
    FrequencySolver() = default;

    std::string next_guess() override {
        throw std::logic_error("TODO: Implement FrequencySolver::next_guess");
    }

    void feedback(const std::string&, const std::string&) override {
        throw std::logic_error("TODO: Implement FrequencySolver::feedback");
    }
};

} // namespace solver
} // namespace wordle
