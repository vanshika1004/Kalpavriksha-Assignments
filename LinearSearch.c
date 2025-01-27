#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void takeInput(int *arr , int size){
    for(int index=0 ; index < size ; index++){
        scanf("%d",&arr[index]);
    }
}

int linearSearch(int *arr, int size, int key){
    for(int i = 0 ; i < size ; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

void printArray(int *arr , int size){
    for(int index = 0 ; index < size ; index++){
        printf("%d " , arr[index]);
    }
    printf("\n");
}
int main(){
    int size;
    while(1){
        printf("Enter the size of array you want to sort.\n");
        scanf("%d" , &size);
        if(size>0){
            break;
        }
        else{
            printf("Enter a positive integer greater than Zero.\n");
        }
    }
    int* arr = (int*)malloc(size * sizeof(int));
    
    takeInput(arr , size);
    
    printf("The array is: \n");
    printArray(arr, size);
    
    int key = 0;
    printf("Enter the element you want to search:\n");
    scanf("%d",&key);
    
    int searchResult = linearSearch(arr, size, key);
    
    if(searchResult != -1){
        printf("%d element is present at index %d\n", key, searchResult);
    }
    else{
        printf("The key element is not present in the array.\n");
    }
    
    free(arr);
    return 0;
}
