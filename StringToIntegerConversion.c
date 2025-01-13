#include<stdio.h>

int checkInput(char *str){
    int i=0;
    while(str[i]!='\0'){
    if(str[0]=='-' || (str[i]>='0' && str[i]<='9')){
        i++;
    }
    else{
        return 0;
    }   
    }
    return 1;
}
void stringToInteger(char *str){
    int i=0,val=0;
    char sign='&';
    while(str[i]!='\0'){
        if(str[0]=='-'){
            sign = '-';
            i++;
        }
        while(str[i]!='\0'){
            int num=str[i]-'0';
            val=val*10+num;
            i++;
        }
        if(sign == '-'){
            val=-val;
        }
    }
    printf("The value after conversion is %d",val);
}
int main(){
    char str[100];
    printf("Enter a string:");
    scanf("%99[^\n]%*c",str);
    
    if(!checkInput(str)){
        printf("0\n");
    }
    else{
        stringToInteger(str);
    }
    return 0;
}