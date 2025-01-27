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

int partition(int *arr , int low , int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        
        while(arr[j] > pivot && j >= low+1){
            j--;
        }
        if(i<j){
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int *arr , int low , int high){
    if(low < high){
         int partitionIdx = partition(arr, low, high);
         
         quickSort(arr,low, partitionIdx-1);
         quickSort(arr,partitionIdx+1,high);
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
    
    quickSort(arr , 0 ,size-1);
    printf("After applying Quick Sort, the array is:\n");
    printArray(arr , size);
    free(arr);
    return 0;
}
