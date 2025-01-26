#include<stdio.h>
#include<stdlib.h>

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

void selectionSort(int *arr , int size){
    for(int i = 0; i < size-1 ; i++){
        int minimumIdx = i;
        for(int j = i+1 ; j < size ; j++){
            if(arr[minimumIdx] > arr[j]){
                minimumIdx = j;
            }
        }
        
        swap(&arr[minimumIdx], &arr[i]);
    }
}

void printArray(int *arr , int size){
    for(int index = 0 ; index < size ; index++){
        printf("%d " , arr[index]);
    }
}
int main(){
    int size;
    printf("Enter the size of array you want to sort.\n");
    scanf("%d" , &size);
    int* arr = (int*)malloc(size * sizeof(int));
    
    takeInput(arr , size);
    
    selectionSort(arr , size);
    printf("After applying selection Sort, the array is:\n");
    printArray(arr , size);
    free(arr);
    return 0;
}
