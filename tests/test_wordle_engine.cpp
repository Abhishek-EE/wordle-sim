#include "engine/wordle_engine.h"
#include <gtest/gtest.h>

using namespace wordle::engine;
// Test exact word match
TEST(WordleEngineTest, ExactMatch) {
    WordleEngine engine("apple");
    std::string fb = engine.guess("apple");

    EXPECT_EQ(fb, "GGGGG");
    EXPECT_TRUE(engine.is_win());
    EXPECT_TRUE(engine.is_finished());
}

// Test one incorrect letter
TEST(WordleEngineTest, PartialMatch) {
    WordleEngine engine("apple");
    std::string fb = engine.guess("apply");

    EXPECT_EQ(fb.substr(0, 4), "GGGG");
    EXPECT_EQ(fb[4], 'B');
    EXPECT_FALSE(engine.is_win());
    EXPECT_FALSE(engine.is_finished());
}

// Test yellow feedback
TEST(WordleEngineTest, YellowFeedback) {
    WordleEngine engine("apple");
    std::string fb = engine.guess("pearl");

    EXPECT_EQ(fb.size(), 5);
    EXPECT_NE(fb.find('Y'), std::string::npos); // at least one 'Y'
}

// Test multiple turns (win before max)
TEST(WordleEngineTest, MultipleTurns) {
    WordleEngine engine("grape", 2);

    engine.guess("apple");
    EXPECT_FALSE(engine.is_finished());

    std::string fb2 = engine.guess("grape");
    EXPECT_TRUE(engine.is_win());
    EXPECT_TRUE(engine.is_finished());
    EXPECT_EQ(fb2, "GGGGG");
}

// Test losing after max turns
TEST(WordleEngineTest, MaxTurnsLoss) {
    WordleEngine engine("grape", 2);

    engine.guess("apple");
    engine.guess("pearl");

    EXPECT_TRUE(engine.is_finished());
    EXPECT_FALSE(engine.is_win());
}

// Test for case insensitive matching
TEST(WordleEngineTest, CaseInsensitiveGuesses) {
    // Secret is lowercase internally
    WordleEngine engine("apple", 6);

    // Uppercase guess
    std::string feedback_upper = engine.guess("GRAPE");

    // Mixed-case guess
    std::string feedback_mixed = engine.guess("GrApE");

    // Lowercase guess
    std::string feedback_lower = engine.guess("grape");

    // Correct guess
    std::string feedback_correct = engine.guess("Apple");

    // All three should yield the same feedback
    EXPECT_EQ(feedback_lower, feedback_upper);
    EXPECT_EQ(feedback_lower, feedback_mixed);

    // Since "apple" matches the secret, feedback must be all G
    EXPECT_EQ(feedback_correct, "GGGGG");
}

// Main test runner
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
