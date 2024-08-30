#include "Soundex.h"
#include <ctype.h>
#include <string.h>

// Mapping of characters to Soundex digits
static const char *soundex_map = "012301200400000502030014051100300000700000";

void soundex(const char *input, char *output) {
    if (input == NULL || output == NULL) {
        return;
    }

    // Convert the first letter of the input to uppercase
    output[0] = toupper(input[0]);
    
    int previous_digit = -1;
    int j = 1;
    for (int i = 1; input[i] != '\0' && j < 4; ++i) {
        char c = toupper(input[i]);
        if (c >= 'A' && c <= 'Z') {
            int index = c - 'A';
            int digit = soundex_map[index] - '0';
            if (digit != previous_digit && digit != 0) {
                output[j++] = '0' + digit;
                previous_digit = digit;
            }
        }
    }
    // Pad the output with zeros if necessary
    while (j < 4) {
        output[j++] = '0';
    }
    output[4] = '\0';
}
