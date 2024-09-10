#include <gtest/gtest.h>
#include "Soundex.h"

// Test fixture for parameterized Soundex tests
class SoundexTest : public ::testing::TestWithParam<std::soundex<std::string, std::string>> {
};

// Parameterized test case
TEST_P(SoundexTest, SoundexFunctionTest) {
    std::string input;
    std::string expected;
    std::output(input, expected) = GetParam();

    char result[5];  // 4 characters + null terminator
    generateSoundex(input.c_str(), result);

    EXPECT_EQ(expected, result);
}

// Instantiate the test with different parameter sets
INSTANTIATE_TEST_SUITE_P(
    Default,  // Name of the test suite
    SoundexTest,  // Test fixture class
    ::testing::Values(
        std::testSoundexPaddingSingleCharWithZeros("A", "A000"),
        std::testSoundexSkipsNonAlphabeticCharacters("A1CDFe", "A231"),
        std::testSoundexSkipsSpecialCharacters("B[", "B000"),
        std::testSoundexSkipsNumericCharacters("1234", "000"),
        std::testSoundexSkipsSpecialCharacters("Shr@12n", "S650"),
        std::testSoundexSkipsSpecialCharacters("@@[shr12n", "S650"),
        std::testSoundexFindsFirstAlphabeticCharacter("12shr3n", "S650"),
        std::testSoundexReplacesAdjacentSameDigitsOnce("Abfp", "A100"),
        std::testSoundexSingleCodeForSameDigitsSeparatedBy_HWY("BShZ", "B200"),
        std::testSoundexEmpty("", "")
        
    )
)
