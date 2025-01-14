#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void stringCompression(char *str){
    int len = strlen(str);
    int k=0;
    char ans[100]="";
    for(int i=0; i<len ;i++){
        int count=1;
        ans[k++]=str[i];
        while(str[i]==str[i+1]){
            count++;
            i++;
        }
        ans[k++]=count+'0';
    }
    if(k>len){
        printf("%s",str);
    }
    else if(k==len){
        printf("%s",ans);
    }
    
}

int main(){
    char* str = (char*)malloc(100 * sizeof(char));
    scanf("%99[^\n]%*c",str);
    
    stringCompression(str);
    free(str);
    return 0;
}
