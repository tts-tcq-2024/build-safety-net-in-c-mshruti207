#include <gtest/gtest.h>
#include "Soundex.h"
 
//Append zeros if result contains less than 3 digits
TEST(SoudexTestsuite, PadZerosForSingleCharacter) {
//AAA
  char soundex[MAX_CODE_LENGTH+1];
  generateSoundex("AX", soundex);
  ASSERT_STREQ(soundex,"A200");
}

//skip numeric and replace consonants with appropriate digit
TEST(SoudexTestsuite, SkipNumericsAndReplaceConsanantsWithDigitCode) {
//AAA
  char soundex[MAX_CODE_LENGTH+1];
  generateSoundex("A1CDFe", soundex);
  ASSERT_STREQ(soundex,"A231");
}
 
//Test case to check special character or entire numeric
TEST(SoudexTestsuite, TestCheckSkipSpecialCharacterAndNumeric) {
//AAA
 char soundex[MAX_CODE_LENGTH+1];
  generateSoundex("A[", soundex);
  ASSERT_STREQ(soundex,"A000");
  generateSoundex("1234", soundex);
  ASSERT_STREQ(soundex,"000");
  generateSoundex("Shr@12n", soundex);
  ASSERT_STREQ(soundex,"S650");
}

//Test case to check special character or numeric at starting
TEST(SoudexTestsuite, TestCheckSpecialCharacterAndNumericAtStarting) {
//AAA
 char soundex[MAX_CODE_LENGTH+1];
  generateSoundex("@@[shr12n", soundex);
  ASSERT_STREQ(soundex,"S650");
  generateSoundex("12shr3n", soundex);
  ASSERT_STREQ(soundex,"S650");
}

//Replace all adjacent same digits with one digit
TEST(SoudexTestsuite, TestCheckReplaceAdjacentSameDigitsOnce) {
//AAA
  char soundex[MAX_CODE_LENGTH+1];
  generateSoundex("Abfp", soundex);
  ASSERT_STREQ(soundex,"A100");
}
 
//two letters with the same number separated by 'h', 'w' or 'y' are coded as a single number
TEST(SoudexTestsuite, TestCheckReplaceWithSinglenumberSeparatedBy_HWY) {
//AAA
 char soundex[MAX_CODE_LENGTH+1];
  generateSoundex("BShZ", soundex);
  ASSERT_STREQ(soundex,"B200");
  generateSoundex("lgwxnm", soundex);
  ASSERT_STREQ(soundex,"L250");
}

//Test case to check Empty 
TEST(SoudexTestsuite, TestCheckEmptyCharacter) {
//AAA
  char soundex[MAX_CODE_LENGTH+1];
  generateSoundex("", soundex);
  ASSERT_STREQ(soundex,"");
}
