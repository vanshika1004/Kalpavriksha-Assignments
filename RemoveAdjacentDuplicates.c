#include <stdio.h>
#include <string.h>
#include<stdlib.h>

void removeAdjDuplicates(char *str){
    int n = strlen(str);
    
    char res[101] = "";
    int k = 0;

    for (int i = 0; i < n; i++){
        int repeated = 0;
        while (i + 1 < n && str[i] == str[i + 1]){
            repeated = 1;
            i++;
        }
        if (!repeated)
            res[k++] = str[i];
    }

    res[k] = '\0';
    if (n == k)
        strcpy(str, res);
    else{
        strcpy(str,res);
        removeAdjDuplicates(str);
    }
}

int main(){
    char* str = (char*)malloc(101 * sizeof(char));
    scanf("%100[^\n]%*c",str);
    removeAdjDuplicates(str);
    printf("%s", str);

    return 0;
}
