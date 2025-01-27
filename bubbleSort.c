#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void takeInput(int *arr , int size){
    for(int index=0 ; index < size ; index++){
        scanf("%d",&arr[index]);
    }
}

void BubbleSort(int *arr , int size){
    for(int i = 1; i < size ; i++){
        bool isSwapped = false;
        for(int j = 0 ; j < size-i ; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                isSwapped = true;
            }
        }
        // checking if array is already sorted 
        if(isSwapped == false)
        break;
    }
}

void printArray(int *arr , int size){
    for(int index = 0 ; index < size ; index++){
        printf("%d " , arr[index]);
    }
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
    
    BubbleSort(arr , size);
    printf("After applying Bubble Sort, the array is:\n");
    printArray(arr , size);
    free(arr);
    return 0;
}