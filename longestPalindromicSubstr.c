#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void longestPalSubstring(char *str,char *res){
    int len=strlen(str);
    if(len == 0){
        res[0]='\0';
        return;
    }

    res[0]=str[0];
    res[1]='\0';
    // for odd length
    for(int i=0;i<len;i++){
        int low = i;
        int high = i;
        while(low>=0 && high<len && str[low]==str[high]){
            low--;
            high++;
        }
        
        low++;
        high--;
        if(high-low+1>strlen(res)){
            strncpy(res,&str[low],high-low+1);
            res[high-low+1]='\0';
        }
        
        // for even length
        low=i;
        high=i+1;
        while(low>=0 && high<len && str[low]==str[high]){
            low--;
            high++;
        }
        
        low++;
        high--;
        if(high-low+1>strlen(res)){
            strncpy(res,&str[low],high-low+1);
            res[high-low+1]='\0';
        }
    }
}
int main(){
    char* str = (char*)malloc(100 * sizeof(char));
    scanf("%99[^\n]%*c",str);
    char* res = (char*)malloc(100 * sizeof(char));

    longestPalSubstring(str,res);
    printf("The longest Palindromic substring is %s",res);
    return 0;
}
