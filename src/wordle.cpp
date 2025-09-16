#include "engine/wordle_engine.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

/**
 * Simple CLI to play Wordle
 * - User has 6 attempts to guess the secret
 * - Feedback shown as 🟩 (green), 🟨 (yellow), ⬜ (gray)
 */

/// Convert feedback string "GYBBY" into emojis

using namespace wordle::engine;

std::string feedback_to_emojis(const std::string& guess, const std::string& feedback) {
    std::string result;
    for (size_t i = 0; i < feedback.size(); i++) {
        char fb = feedback[i];
        if (fb == 'G') {
            result += "🟩";
        } else if (fb == 'Y') {
            result += "🟨";
        } else {
            result += "⬜";
        }
    }
    result += "   " + guess;
    return result;
}

int main() {
    std::srand(std::time(nullptr));

    // Example dictionary (could later load from words.txt)
    std::vector<std::string> dictionary = {
        "apple", "grape", "melon", "berry", "pearl", "mango"
    };

    // Pick a random secret word
    std::string secret = dictionary[std::rand() % dictionary.size()];

    WordleEngine engine(secret, 6);

    std::cout << "=== Welcome to Wordle (CLI version) ===\n";
    std::cout << "Guess the 5-letter word! You have 6 attempts.\n\n";

    while (!engine.is_finished()) {
        std::cout << "Enter guess (" << (6 - engine.turns()) << " left): ";
        std::string guess;
        std::cin >> guess;

        // Validate guess length
        if (guess.size() != 5) {
            std::cout << "Guess must be 5 letters.\n";
            continue;
        }

        try {
            std::string feedback = engine.guess(guess);
            std::cout << feedback_to_emojis(guess, feedback) << "\n";

            if (engine.is_win()) {
                std::cout << "\n🎉 You won in " << engine.turns() << " turns! 🎉\n";
                return 0;
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    std::cout << "\n❌ You lost. The word was: " << engine.secret() << "\n";
    return 0;
}
