#include<stdio.h>
#include<stdlib.h>

void removeDuplicates(char *str,char* s){
    int i=0,k=0;
    int arr[256]={0};
    while(str[i]!='\0'){
        if(arr[str[i]]==0){
            s[k++]=str[i];
            arr[str[i]]++;
        }
        i++;
    }
}

int findLength(char *str){
    int len=0;
    int i=0;
    while(str[i]!='\0'){
        len++;
        i++;
    }
    return len;
}
int main(){
    char *str = (char *)malloc(100 * sizeof(char));
    char ans[100]="";
    printf("Enter the string: ");
    fgets(str,100,stdin);
    int len=findLength(str);
    str[len-1]='\0';
    removeDuplicates(str,ans);
    printf("The string after removing duplicates is %s.\n",ans);
    free(str);
    return 0;
}