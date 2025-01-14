#include <stdio.h>
#include <string.h>
#include<stdlib.h>

void findLongestPalSubstr(char *str, char *ans) {
    int n = strlen(str);
    if (n == 0) {
        ans[0] = '\0';
        return;
    }

    int start = 0, maxLen = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 1; j++) {
            int low = i;
            int high = i + j; 

            while (low >= 0 && high < n && str[low] == str[high]) {
                int currLen = high - low + 1;
                if (currLen > maxLen) {
                    start = low;
                    maxLen = currLen;
                }
                low--;
                high++;
            }
        }
    }

    strncpy(ans, str + start, maxLen);
    ans[maxLen] = '\0';
}

int main() {
    char* str = (char*)malloc(100 * sizeof(char));
    scanf("%99[^\n]%*c",str);
    char* ans = (char*)malloc(100 * sizeof(char));
    findLongestPalSubstr(str, ans);
    printf("%s\n", ans);
    return 0;
}
