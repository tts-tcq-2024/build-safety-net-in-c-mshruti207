#include <gtest/gtest.h>
#include "Soundex.h"

// Test fixture for parameterized Soundex tests
class SoundexTest : public ::testing::TestWithParam<std::tuple<std::string, std::string>> {
};

// Parameterized test case
TEST_P(SoundexTest, SoundexFunctionTest) {
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
        std::make_tuple("A", "A000"), //testSoundex for Padding Single Character With Zeros
        std::make_tuple("A1CDFe", "A231"),//testSoundex to Skip NonAlphabetic Characters
        std::make_tuple("B[", "B000"),//testSoundex to Skip SpecialCharacters
        std::make_tuple("1234", "000"),//testSoundex to Skip NumericCharacters
        std::make_tuple("Shr@12n", "S650"),//testSoundex to Skip SpecialCharacters
        std::make_tuple("@@[shr12n", "S650"),//testSoundex to Find First Alphabetic Character and Skip SpecialCharacters
        std::make_tuple("12shr3n", "S650"),//testSoundex to Find First Alphabetic Character and Skip numeric
        std::make_tuple("Abfp", "A100"),//testSoundex to Replace Adjacent Same Digits Once
        std::make_tuple("BShZ", "B200"),//testSoundex to SingleCode For Same Digits Separated By "HWY"
        std::make_tuple("", "")//testSoundex for Empty
        
    )
)
