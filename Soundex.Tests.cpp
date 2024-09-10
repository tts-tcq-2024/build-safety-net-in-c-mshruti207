#include <gtest/gtest.h>
#include "Soundex.h"

// Test fixture for parameterized Soundex tests
class SoundexTest : public ::testing::TestWithParam<std::tuple<std::string, std::string>> {
};

// Parameterized test case
TEST_Soundex(SoundexTest, SoundexFunctionTest) {
    std::string input;
    std::string expected;
    std::tie(input, expected) = GetParam();

    char result[5];  // 4 characters + null terminator
    generateSoundex(input.c_str(), result);

    EXPECT_EQ(expected, result);
}

// Instantiate the test with different parameter sets
INSTANTIATE_TEST_SUITE_P(
    Default,  // Name of the test suite
    SoundexTest,  // Test fixture class
    ::testing::Values(
        std::make_tuple("A", "A000"),
        std::make_tuple("A1CDFe", "A231"),
        std::make_tuple("B[", "B000"),
        std::make_tuple("1234", "000"),
        std::make_tuple("Shr@12n", "S650"),
        std::make_tuple("@@[shr12n", "S650"),
        std::make_tuple("12shr3n", "S650"),
        std::make_tuple("Abfp", "A100"),
        std::make_tuple("BShZ", "B200"),
        std::make_tuple("", "")
    )
);
