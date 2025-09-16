#pragma once
#include <string>
#include <vector>

#pragma once
#include <string>
#include <vector>

namespace wordle::engine{
/**
 * @brief WordleEngine implements the Wordle game logic.
 *
 * This class manages:
 *  - The secret word
 *  - Number of turns
 *  - Validating guesses
 *  - Generating feedback strings
 *
 * Feedback encoding:
 *   - 'G' = Green (correct letter, correct position)
 *   - 'Y' = Yellow (letter present but wrong position)
 *   - 'B' = Black/Gray (letter not present)
 */
class WordleEngine {
public:
    /**
     * @brief Construct a WordleEngine
     * @param secret The target word (must be 5 letters).
     * @param max_turns Maximum number of guesses (default = 6).
     */
    WordleEngine(const std::string& secret, int max_turns = 6);

    /**
     * @brief Make a guess and get feedback.
     * @param guess The guessed word (must be same length as secret).
     * @return A feedback string of length N with characters 'G', 'Y', 'B'.
     * @throws std::invalid_argument if guess length mismatches.
     */
    std::string guess(const std::string& guess);

    /**
     * @brief Check if the last guess was correct.
     * @return True if the last guess matched the secret.
     */
    bool is_win() const;

    /**
     * @brief Check if the game has ended.
     * Game ends if player wins or max turns reached.
     */
    bool is_finished() const;

    /**
     * @brief Get number of turns already used.
     */
    int turns() const { return turns_; }

    /**
     * @brief Get the secret word (for simulation/statistics).
     */
    std::string secret() const { return secret_; }

private:
    std::string secret_;
    int max_turns_;
    int turns_;
    bool finished_;
    bool win_;
};
} //namespace wordle::engine

