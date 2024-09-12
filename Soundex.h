#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

#define MAX_CODE_LENGTH 4


char getSoundexCode(char c) {
    static const char soundexTable[26] = { '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'  }; // Soundex encoding table where index corresponds to the letter 
                                                                                                                                                                                 //  (A=0, B=1, C=2, D=3, E=0, F=1, G=2, H=0, I=0, J=2, K=2, L=4, M=5, N=5,
                                                                                                                                                                                 // O=0, P=1, Q=2, R=6, S=2, T=3, U=0, V=1, W=0, X=2, Y=0, Z=2)
    if (c >= 'A' && c <= 'Z') {
        return soundexTable[c - 'A'];
    }
    return '0'; 
}

void addSoundexCode(char* soundex, int* sIndex, char code) {
    if (code != '0' && code != soundex[*sIndex - 1]) {
        soundex[(*sIndex)++] = code;
    }
}

void processCharacters(const char* name, char* soundex, int* index) {
   int sIndex=1;

    for (int i = *(index) + 1 ; name[i] && sIndex < MAX_CODE_LENGTH; i++) {
        char code = getSoundexCode(toupper(name[i]));
            addSoundexCode(soundex, &sIndex, code);
        }    
}

void initializeSoundex(char* soundex, char firstLetter) {
    soundex[0] = toupper(firstLetter);
    for (int i = 1; i < MAX_CODE_LENGTH; i++) {
        soundex[i] = '0';
    }
}

int findFirstAlphabetic_char(const char* name) {
    int index = 0;
    while (name[index] && !isalpha((unsigned char)name[index])) {
        index++;
    }
    return index; 
}


void FindFirstAlphabeticCharacter(const char* name, char* soundex) {
    int index = findFirstAlphabetic_char(name);
    if (index != -1) {        
        initializeSoundex(soundex, name[index]);  
        processCharacters(name, soundex, &index); 
    } else {
        soundex[0] = '\0'; 
    }
}

void padding_Soundex(char *soundex) {
    int len = strlen(soundex);
    while (len < MAX_CODE_LENGTH - 1) {
        soundex[len++] = '0';
    }
    soundex[len] = '\0'; 
}

void generateSoundex(const char* name, char* soundex) {
    if (name == NULL || name[0] == '\0') {
        soundex[0] = '\0';
        return;
    }
    FindFirstAlphabeticCharacter(name, soundex);
    padding_Soundex(soundex);
}

#endif // SOUNDEX_H
