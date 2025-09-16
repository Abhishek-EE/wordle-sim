#include <string>
#include <algorithm>
#include <cctype>
#include "engine/utils.h"

namespace wordle::engine {
std::string to_lower(const std::string& s) {
    std::string result = s;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return result;
}
}