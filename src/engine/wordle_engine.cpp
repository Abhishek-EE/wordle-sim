#include "engine/wordle_engine.h"
#include <stdexcept>
#include <unordered_map>
#include "engine/utils.h"


namespace wordle::engine {
WordleEngine::WordleEngine(const std::string& secret, int max_turns)
    : secret_(to_lower(secret)), max_turns_(max_turns), turns_(0),
      finished_(false), win_(false) {
    if (secret_.size() != 5) {
        throw std::invalid_argument("Secret word must be 5 letters.");
    }
}

std::string WordleEngine::guess(const std::string& word) {
    std::string guess = to_lower(word);
    if (finished_) {
        throw std::runtime_error("Game already finished.");
    }
    if (guess.size() != secret_.size()) {
        throw std::invalid_argument("Guess length mismatch.");
    }

    turns_++;

    std::string feedback(secret_.size(), 'B');
    std::unordered_map<char, int> secret_freq;

    // Count letters in secret
    for (char c : secret_) {
        secret_freq[c]++;
    }

    // Pass 1: mark Greens
    for (size_t i = 0; i < guess.size(); i++) {
        if (guess[i] == secret_[i]) {
            feedback[i] = 'G';
            secret_freq[guess[i]]--;
        }
    }

    // Pass 2: mark Yellows
    for (size_t i = 0; i < guess.size(); i++) {
        if (feedback[i] == 'B') {
            char g = guess[i];
            if (secret_freq[g] > 0) {
                feedback[i] = 'Y';
                secret_freq[g]--;
            }
        }
    }

    if (feedback == std::string(secret_.size(), 'G')) {
        win_ = true;
        finished_ = true;
    } else if (turns_ >= max_turns_) {
        finished_ = true;
    }

    return feedback;
}

bool WordleEngine::is_win() const {
    return win_;
}

bool WordleEngine::is_finished() const {
    return finished_;
}
} //namespace wordle::engine