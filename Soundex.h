#include <stdio.h>
#include <string.h>
#include <ctype.h>

void soundex(const char *name, char *s) {
    // Soundex mapping table
    char mappings[] = "01230120022455012623010202";
    // Initialize the output string
    s[0] = toupper(name[0]);
    int si = 1;

    // Process each character in the input name
    for (int i = 1; name[i] != '\0' && si < 4; i++) {
        char c = toupper(name[i]);
        if (c >= 'A' && c <= 'Z') {
            char code = mappings[c - 'A'];
            if (code != '0' && code != s[si - 1]) {
                s[si++] = code;
            }
        }
    }

    // Pad with zeros if necessary
    while (si < 4) {
        s[si++] = '0';
    }

    // Null-terminate the string
    s[si] = '\0';
}
