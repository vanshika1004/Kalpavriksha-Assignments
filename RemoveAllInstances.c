#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void removeAllInstances(char *str,char ch){
    int i=0,j=0;
    while(str[i]!='\0'){
        if(str[i]!=ch){
            str[j++]=str[i];
        }
        i++;
    }
    str[j]='\0';

}
int main(){
    char *str = (char*)malloc(100 * sizeof(char));
    printf("Enter the string:");
    // fgets(str,100,stdin);
    // int len=strlen(str);
    // if(len>0 && str[len-1]=='\n'){
    //     str[len-1]='\0';
    // }
    scanf("%99[^\n]%*c",str);
    printf("Enter the character whose instances you want to remove:");
    char ch;
    scanf("%c",&ch);
    removeAllInstances(str,ch);
    printf("The string after removing all instances of %c is %s",ch,str);
    
    free(str);
    return 0;
}