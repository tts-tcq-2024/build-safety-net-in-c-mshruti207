#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to calculate the Soundex code
void soundex(const char *name, char *result) {
    // Soundex mapping table
    const char map[26] = {
        0, // A
        1, // B
        2, // C
        3, // D
        0, // E
        1, // F
        2, // G
        0, // H
        0, // I
        1, // J
        2, // K
        0, // L
        5, // M
        5, // N
        0, // O
        1, // P
        2, // Q
        6, // R
        2, // S
        3, // T
        0, // U
        1, // V
        0, // W
        2, // X
        0, // Y
        2  // Z
    };

    if (name[0] == '\0') {
        strcpy(result, "0000");
        return;
    }

    // Result buffer and initialization
    result[0] = toupper(name[0]); // First letter
    int index = 1; // Position in result

    char prevCode = map[toupper(name[0]) - 'A']; // Code for the first letter

    for (int i = 1; name[i] != '\0' && index < 4; i++) {
        char ch = toupper(name[i]);
        char code = map[ch - 'A'];

        if (code != 0 && code != prevCode) {
            result[index++] = '0' + code;
        }
        prevCode = code;
    }

    // Pad with zeros if needed
    while (index < 4) {
        result[index++] = '0';
    }
    result[4] = '\0'; // Null-terminate the string
}
