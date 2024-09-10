#include <gtest/gtest.h>
#include <cstring>
#include "Soundex.h"  // Include your Soundex header file

class SoundexTest : public ::testing::TestWithParam<std::tuple<std::string, std::string>> {
};

TEST_P(SoundexTest, CorrectSoundexEncoding) {
    auto [input, expected] = GetParam();
    char result[SOUND_EX_MAX_LENGTH + 1];
    generatesoundex(input.c_str(), result);
    EXPECT_EQ(expected, std::string(result));
}

INSTANTIATE_TEST_SUITE_P(
    SoundexTests,
    SoundexTest,
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
