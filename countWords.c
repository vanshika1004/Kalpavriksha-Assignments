#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int checkCharacter(char ch){
    if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') ){
        return 1;
    }
    else
    return 0;
}

int countWords(char *str) {
    int count = 0, i = 0;

    while (str[i] != '\0') {
        
        while (str[i] != '\0' && !checkCharacter(str[i])) {
            i++;
        }

        if (str[i] != '\0' && checkCharacter(str[i])) {
            count++;
            while (str[i] != '\0' && checkCharacter(str[i])) {
                i++;
            }
        }
    }
    return count;
}

int findLength(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int main() {
    char *str = (char *)malloc(1024 * sizeof(char));
    if (!str) {
        printf("Error in memory allocation.\n");
        return 1;
    }

    printf("Enter the string: ");
    fgets(str, 1024, stdin);

    int len = findLength(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    int count = countWords(str);
    printf("Number of words: %d\n", count);

    free(str);

    return 0;
}