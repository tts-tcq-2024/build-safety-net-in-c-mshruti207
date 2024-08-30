#include <check.h>
#include <string.h>
#include "soundex.h"

// Test case for the Soundex algorithm
START_TEST(test_soundex_basic) {
    char output[5];

    soundex("Smith", output);
    ck_assert_str_eq(output, "S530");

    soundex("Jackson", output);
    ck_assert_str_eq(output, "J025");

    soundex("Robert", output);
    ck_assert_str_eq(output, "R163");
}
END_TEST

START_TEST(test_soundex_edge_cases) {
    char output[5];

    // Test with empty string
    soundex("", output);
    ck_assert_str_eq(output, "0000");

    // Test with single letter
    soundex("A", output);
    ck_assert_str_eq(output, "A000");

    // Test with all same letters
    soundex("AAAAA", output);
    ck_assert_str_eq(output, "A000");

    // Test with mixed letters
    soundex("McDonald", output);
    ck_assert_str_eq(output, "M235");
}
END_TEST

// Suite setup and teardown
Suite* soundex_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Soundex");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_soundex_basic);
    tcase_add_test(tc_core, test_soundex_edge_cases);
    suite_add_tcase(s, tc_core);

    return s;
}

// Main function to run the tests
int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = soundex_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
