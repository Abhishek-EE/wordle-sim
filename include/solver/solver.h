#pragma once

#include <string>

namespace wordle {
namespace solver {

// Abstract base solver
class Solver {
public:
    virtual ~Solver() = default;

    // Decide next guess
    virtual std::string next_guess() = 0;

    // Notify solver about feedback from engine
    virtual void feedback(const std::string& guess, const std::string& result) = 0;
};

} // namespace solver
} // namespace wordle
