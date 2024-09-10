#include <gtest/gtest.h>
#include "soundex.h"

// Test fixture for parameterized Soundex tests
class SoundexTest : public ::testing::TestWithParam<std::tuple<std::string, std::string>> {
};

// Parameterized test case
TEST_P(SoundexTest, SoundexFunctionTest) {
    std::string input;
    std::string expected;
    std::tie(input, expected) = GetParam();

    char result[5];  // 4 characters + null terminator
    soundex(input.c_str(), result);

    EXPECT_EQ(expected, result);
}

// Instantiate the test with different parameter sets
INSTANTIATE_TEST_SUITE_P(
    Default,  // Name of the test suite
    SoundexTest,  // Test fixture class
    ::testing::Values(
        std::make_tuple("Robert", "R163"),
        std::make_tuple("Rupert", "R163"),
        std::make_tuple("Rubin", "R150"),
        std::make_tuple("Ashcraft", "A261"),
        std::make_tuple("Harris", "H020"),
        std::make_tuple("Jackson", "J252"),
        std::make_tuple("Leigh", "L020"),
        std::make_tuple("Smith", "S530"),
        std::make_tuple("Smythe", "S530")
    )
);
