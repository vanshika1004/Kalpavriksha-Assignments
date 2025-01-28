#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void takeInput(int *arr , int size){
    for(int index=0 ; index < size ; index++){
        scanf("%d",&arr[index]);
    }
}

int BinarySearch(int *arr, int size, int key){
    int s = 0;
    int e = size - 1;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(arr[mid] == key){
            return mid;
        }
        else if(key < arr[mid]){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
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
    
    int searchResult = BinarySearch(arr, size, key);
    
    if(searchResult != -1){
        printf("%d element is present at index %d\n", key, searchResult);
    }
    else{
        printf("The key element is not present in the array.\n");
    }
    
    free(arr);
    return 0;
}
