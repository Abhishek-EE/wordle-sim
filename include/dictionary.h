#pragma once

#include <string>
#include <vector>
#include <stdexcept>

namespace wordle {

class Dictionary {
public:
    Dictionary() = default;

    // Load words from file
    std::vector<std::string> load_from_file(const std::string& path) {
        throw std::logic_error("TODO: Implement Dictionary::load_from_file");
    }

    // Return a random word
    std::string random_word() const {
        throw std::logic_error("TODO: Implement Dictionary::random_word");
    }

private:
    std::vector<std::string> words_;
};

} // namespace wordle
