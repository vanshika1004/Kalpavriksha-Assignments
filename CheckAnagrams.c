#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int checkAnagrams(char *str1,char *str2){
    int arr[256]={0},i=0,j=0;
    
    int str1Len=strlen(str1);
    int str2Len=strlen(str2);
    if(str1Len!=str2Len){
        return 0;
    }
    
    for(int i=0;i<str1Len;i++){
        arr[str1[i]]++;
        arr[str2[i]]--;
    }
    
    for(int i=0;i<256;i++){
        if(arr[i]!=0){
            return 0;
        }
    }
    return 1;
}


int main(){
    char* str1 = (char*)malloc(100*sizeof(char));
    char* str2= (char*)malloc(100*sizeof(char));
    
    if (str1 == NULL || str2 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    printf("Enter the first string:");
    fgets(str1,100,stdin);
    int str1Len=strlen(str1);
    if(str1Len>0 && str1[str1Len-1]=='\n'){
        str1[str1Len-1]=='\0';
    }
    
    printf("Enter the second string:");
    fgets(str2,100,stdin);
    int str2Len=strlen(str2);
    if(str2Len>0 && str2[str2Len-1]=='\n'){
        str2[str2Len-1]=='\0';
    }
    
    int ans=checkAnagrams(str1,str2);
    if(ans){
        printf("Both are anagrams\n");
    }
    else{
        printf("Both are not anagrams\n");
    }
    free(str1);
    free(str2);
    
    return 0 ;
}