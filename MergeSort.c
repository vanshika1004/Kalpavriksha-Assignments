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

void merge(int *arr , int start , int mid , int end){
     int len1 = mid - start + 1;
     int len2 = end - mid;
     
     int* leftArray = (int*)malloc(len1 * sizeof(int));
     int* rightArray = (int*)malloc(len2 * sizeof(int));
     
     for(int i = 0; i < len1 ; i++){
         leftArray[i] = arr[start+i];
     }
     for(int j = 0 ; j < len2 ; j++){
         rightArray[j] = arr[mid+1+j];
     }
     
     int i = 0 ,j =0 ,k = start;
     while(i < len1 && j < len2){
         if(leftArray[i] <= rightArray[j]){
             arr[k++] = leftArray[i];
             i++;
         }
         else{
             arr[k++] = rightArray[j];
             j++;
         }
     }
     
     while(i < len1){
         arr[k++] = leftArray[i++];
     }
     while(j < len2){
         arr[k++] = rightArray[j++];
     }
     
     free(leftArray);
     free(rightArray);
}

void mergeSort(int *arr , int start,int end){
    if(start<end){
        int mid = start + (end - start)/2;
        // recursively sorting first & second halves
        mergeSort(arr , start , mid);
        mergeSort(arr , mid + 1 , end);
        // finally merging both sorted halves
        merge(arr, start , mid , end);
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
    
    mergeSort(arr , 0 , size-1);
    printf("After applying mergeSort, the array is:\n");
    printArray(arr , size);
    free(arr);
    return 0;
}
