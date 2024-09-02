#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generate_soundex("AX", soundex);
  ASSERT_EQ(soundex,"A200");
}
