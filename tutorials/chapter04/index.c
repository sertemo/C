// código de la función index

# include <stdio.h>

int custom_index(char s[], char t[]) {  // returns index of t in s, -1 if not found
    int i, j, k;

    for (i = 0; s[i] != '\0'; ++i) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k);
        if (k > 0 && t[k] == '\0') {
            return i;
        }
    }
    return -1;
}