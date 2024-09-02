#include <stdio.h>
#include <ctype.h>

// Function to map characters to their Soundex codes
char get_soundex_code(char c) {
    static const char *soundex_mapping = "012301200224550321111112131112132211221";
    if (isalpha(c)) {
        return soundex_mapping[c - 'A'];
    }
    return '0'; // Non-alphabetic characters are mapped to '0'
}

// Function to process the first character and initialize the Soundex code
void initialize_soundex(const char *input, char *output) {
    if (input[0] != '\0') {
        output[0] = toupper(input[0]);
    } else {
        output[0] = '0';
        output[1] = '0';
        output[2] = '0';
        output[3] = '\0';
    }
}

// Function to process the remaining characters of the input string
void process_characters(const char *input, char *output) {
    char prev_char_code = '0';
    int j = 1; // Start after the first letter

    for (int i = 1; input[i] != '\0' && j < 4; ++i) {
        char c = toupper(input[i]);
        char char_code = get_soundex_code(c);

        // Skip duplicate codes and '0' (silent letters)
        if (char_code != '0' && char_code != prev_char_code) {
            output[j++] = char_code;
        }

        prev_char_code = char_code;
    }
}

// Function to pad the Soundex code with zeros if necessary
void pad_soundex(char *output) {
    while (output[1] != '\0' && output[1] != '0') {
        output[2] = '0';
        output[3] = '\0';
    }
}

// Main Soundex function that integrates all the sub-functions
void generate_soundex(const char *input, char *output) {
    // Initialize the output with the first character
    initialize_soundex(input, output);

    // Process the rest of the input string
    process_characters(input, output);

    // Pad with zeros if the output is less than 4 characters
    pad_soundex(output);
}


