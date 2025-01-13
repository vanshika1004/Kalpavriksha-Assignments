#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkSubstring(char* str, char* substr, int *index) {
    int i = 0;
    int strLen = strlen(str);
    int substrLen = strlen(substr);
    while (i <= strLen - substrLen) {
        int j = 0;

        while (str[i] == ' ') {
            i++;
        }

        if (str[i] == substr[j]) {
            while (substr[j] != '\0' && str[i] == substr[j]) {
                i++;
                j++;
            }
            if (substr[j] == '\0') {
                *index = i - j; 
                return;
            }
        } 
        else {
            i++;
        }
    }
    *index = -1;
}

int main() {
    char* str = (char*)malloc(100 * sizeof(char));
    char* substr = (char*)malloc(100 * sizeof(char));
    if (str == NULL || substr == NULL) {
        printf("Error! Memory allocation failed.\n");
        return 0;
    }

    printf("Enter the string: ");
    fgets(str, 100, stdin);
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0'; 
    }

    printf("Enter the substring: ");
    fgets(substr, 100, stdin);
    int len1 = strlen(substr);
    if (len1 > 0 && substr[len1 - 1] == '\n') {
        substr[len1 - 1] = '\0'; 
    }

    if (len1 > len || len1 == 0 || len == 0) {
        printf("Can't find the substring.\n");
    } else {
        int index = -1;
        checkSubstring(str, substr, &index);
        if (index == -1) {
            printf("Index is %d as \"%s\" is not present in the given \"%s\".\n", index, substr, str);
        } else {
            printf("Index is %d\n", index);
        }
    }

    free(str);
    free(substr);
    return 0;
}