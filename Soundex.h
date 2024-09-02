#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to calculate the Soundex code
void generate_soundex(const char *name, char *result) {
    // Soundex mapping table
    const char map[26] = {
        0, 1, 2, 3, 0, 1, 2, 0, 0, 1, 2, 0, 5, 5, 0, 1, 2, 6, 2, 3, 0, 1, 0, 2, 0, 2
    };

    // Handle empty input
    if (name[0] == '\0') {
        strcpy(result, "0000");
        return;
    }

    // Initialize result
    result[0] = toupper(name[0]); // First letter
    int index = 1; // Position in result
    char prevCode = map[toupper(name[0]) - 'A']; // Code for the first letter

    // Process remaining characters
    for (int i = 1; name[i] != '\0' && index < 4; i++) {
        char ch = toupper(name[i]);
        char code = map[ch - 'A'];

        // Add new code if it's not the same as the previous one
        if (code != 0 && code != prevCode) {
            result[index++] = '0' + code;
            prevCode = code;
        }
    }

    // Pad with zeros if needed
    while (index < 4) {
        result[index++] = '0';
    }
    result[4] = '\0'; // Null-terminate the string
}
