#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxWords 100
#define maxLength 100

void printLongestWord(char words[][maxLength],int wordCount){
    char longestWord[maxLength]="";
    for(int i=0;i<wordCount;i++){
        if(strlen(words[i])>strlen(longestWord)){
            strcpy(longestWord,words[i]);
        }
    } 
    printf("The longest word is %s",longestWord);
}

int tokenization(char *str,char words[][maxLength]){
    int wordCount = 0;
    int i=0;
    while(str[i]!='\0'){
        int j=0;
        // skip spaces
        while(str[i]==' '){
            i++;
        }
        if(str[i]=='\0')
        break;
    
        // storing words
        while(str[i]!=' ' && str[i]!='\0'){
            words[wordCount][j++]=str[i++];
        }
        words[wordCount][j]='\0';
        wordCount++;
    }
    return wordCount;
}

int main(){
    char* str = (char*)malloc(100 * sizeof(char));
    scanf("%99[^\n]%*c",str);
    
    if(strlen(str)==0){
        printf("This is empty string.Please enter a valid string\n");
        return 0;
    }
    char words[maxWords][maxLength];
    int wordCount=tokenization(str,words);
    // this function prints the longestWord in the string
    printLongestWord(words,wordCount);
    free(str);
    return 0;
}