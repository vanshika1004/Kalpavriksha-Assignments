#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int checkRotations(char *str1, char *str2) {
    int len = strlen(str1);

    for (int i = 0; i < len; ++i) {
        if (strcmp(str1, str2) == 0)
            return 1;

        char last = str1[len-1];
        for (int j = len-1; j > 0; j--) {
            str1[j] = str1[j-1];
        }
        str1[0] = last;
    }
    return 0;
}

int main() {
    char* str1 = (char*)malloc(100 * sizeof(char));
    scanf("%99[^\n]%*c",str1);
    
    char* str2 = (char*)malloc(100 * sizeof(char));
    scanf("%99[^\n]%*c",str2);

    if(checkRotations(str1,str2)){
        printf("true");
    }
    else{
        printf("false");
    }
    return 0;
}
