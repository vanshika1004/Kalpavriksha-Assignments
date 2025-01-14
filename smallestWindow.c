#include <limits.h>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

char *smallestWindow(char *str, char *pat)
{
    int len1 = strlen(str);
    int len2 = strlen(pat);
    
    if (len1 < len2) return "-1";
    
    int hashPat[256] = {0};
    int hashStr[256] = {0};

    for (int i = 0; i < len2; i++) {
     hashPat[pat[i]]++;   
    }

    int start = 0, start_idx = -1, minLen = INT_MAX;

    int count = 0;

    for (int j = 0; j < len1; j++){
        hashStr[str[j]]++;

        if (hashPat[str[j]] != 0 && hashStr[str[j]] <= hashPat[str[j]]){
            count++;
        }

        if (count == len2)
        {
            while (hashStr[str[start]] > hashPat[str[start]] || hashPat[str[start]] == 0)
            {
                if (hashStr[str[start]] > hashPat[str[start]])
                {
                    hashStr[str[start]]--;
                }
                start++;
            }

            int len_window = j - start + 1;
            if (minLen > len_window)
            {
                minLen = len_window;
                start_idx = start;
            }
        }
    }

    if (start_idx == -1)
    {
        return "-1";
    }

    static char result[100];
    strncpy(result, str + start_idx, minLen);
    result[minLen] = '\0';
    return result;
}

int main()
{
    char* str = (char*)malloc(100 * sizeof(char));
    scanf("%99[^\n]%*c",str);
    
    char* pat = (char*)malloc(100 * sizeof(char));
    scanf("%99[^\n]%*c",pat);

    char *result = smallestWindow(str, pat);
    printf("%s\n", result);

    return 0;
}
