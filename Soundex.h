#include <string.h>
#include <ctype.h>

// Function to encode a single character according to the Soundex rules
char soundexEncodeChar(char c) {
    switch (c) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0';  // For vowels and other characters
    }
}

// Function to encode a string into its Soundex representation
void soundexEncode(const char* input, char* output) {
    // The first character of the Soundex code is the first character of the input
    output[0] = toupper(input[0]);
    int outputIndex = 1;
    
    char previousCode = soundexEncodeChar(toupper(input[0]));
    
    for (int i = 1; input[i] != '\0'; ++i) {
        char currentChar = toupper(input[i]);
        char currentCode = soundexEncodeChar(currentChar);
        
        if (currentCode != '0' && currentCode != previousCode) {
            output[outputIndex++] = currentCode;
        }
        
        previousCode = currentCode;
    }
    
    // Fill the rest of the output with '0' to make sure it's 4 characters long
    while (outputIndex < 4) {
        output[outputIndex++] = '0';
    }
    
    output[4] = '\0';  // Null-terminate the output string
}
