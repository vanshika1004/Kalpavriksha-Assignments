#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int checkRotations(char* str1, char* str2) {
  
    int len = strlen(str1);
    char* concatString = (char*)malloc(2 * len + 1);
    strcpy(concatString, str1);
    strcat(concatString, str1);

    int ans = strstr(concatString, str2) != NULL;
    free(concatString);
    return ans;
}

int main() {
    char* str1 = (char*)malloc(100 * sizeof(char));
    scanf("%99[^\n]%*c",str1);
    
    char* str2 = (char*)malloc(100 * sizeof(char));
    scanf("%99[^\n]%*c",str2);

    printf("%s\n", checkRotations(str1, str2) ? "true" : "false");
    free(str1);
    free(str2);
    return 0;
}
