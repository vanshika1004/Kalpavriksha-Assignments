#include<stdio.h>
#include<string.h>

int includesVowel(char *ch){
    if((*ch=='A' || *ch=='E' || *ch=='I' || *ch=='O' || *ch=='U') || (*ch=='a' || *ch=='e' || *ch=='i' || *ch=='o' || *ch=='u'))
    return 1;
    else
    return 0;
}

int findLength(char name[50]){
    int length=0;
    int i=0;
    while(name[i]!='\0'){
        length++,i++;
    }
    return length;
}

int main(){
    int rows,cols;
    int count=0;
    char longestName[50];
    while(1){
        printf("Enter the number of rows ranging 1-10: ");
        scanf("%d",&rows);
        if(rows<1 || rows>10){
            printf("Error! Enter correct input.\n");
        }
        else{
            break;
        }
    }
    while(1){
        printf("Enter the number of cols ranging 1-101: ");
        scanf("%d",&cols);
        if(cols<1 || cols>101){
            printf("Error! Enter correct input.\n");
        }
        else{
            break;
        }
    }

    char charray[rows][cols][50];
    printf("Enter the names:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("Name at (%d,%d): ",i,j);
            scanf("%s",charray[i][j]);
        }
    }

    printf("The 2D array of names is:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%s ",charray[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(includesVowel(&charray[i][j][0])){
                count++;
            }

            if(findLength(charray[i][j])>findLength(longestName))
            strcpy(longestName,charray[i][j]);
        }
    }

    printf("Number of names starting with a vowel: %d\n",count);
    printf("The longest Name:%s\n",longestName);

}