#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

#define MAX_CODE_LENGTH 4

// Maps each letter to its Soundex code
char getSoundexCode(char c) {
    static const char soundexTable[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
    };
   c = toupper(c);
    if (!isalpha(c))
    {      
        return 0;  
    }
  return soundexTable[c - 'A']; // Non-alphabetic characters are mapped to '0'
}

// Initialize the Soundex code with the first letter and default values
void initializeSoundex(char* soundex, char firstLetter) {
    soundex[0] = toupper(firstLetter);
    for (int i = 1; i < MAX_CODE_LENGTH; i++) {
        soundex[i] = '0';
    }
   }

// Add a Soundex code to the result if it's valid and different from the last code
void addSoundexCode(char* soundex, int* sIndex, char code) {
    if (code != '0' && code != soundex[*sIndex - 1]) {
        soundex[(*sIndex)++] = code;
    }
}

// Process the remaining characters of the name to generate the Soundex code
void processCharacters(const char* name, char* soundex) {
    int sIndex = 1; // Start adding codes after the first letter

    for (int i = 1; name[i] && sIndex < MAX_CODE_LENGTH; i++) {
        char code = getSoundexCode(toupper(name[i]));
        addSoundexCode(soundex, &sIndex, code);
      
    }
}

// Pad the Soundex code if necessary
void padding_Soundex(char *soundex) {
    int len = strlen(soundex);
    while (len < MAX_CODE_LENGTH - 1) { // -1 because the last position is for '\0'
        soundex[len++] = '0';
        soundex[len] = '\0'; // Ensure null-termination
    }
}

// Generate the Soundex code from the given name
void generateSoundex(const char* name, char* soundex) {
    if (name == NULL || name[0] == '\0') {
        soundex[0] = '\0';
        return;
    }
   
    initializeSoundex(soundex, name[0]);
    processCharacters(name, soundex);
    padding_Soundex(soundex);
}

#endif // SOUNDEX_H
