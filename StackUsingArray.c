#include<stdio.h>
#include<stdlib.h>

int maxSize = 0,choice = 0 , StackTop = -1;
int *arr;
int isEmpty(){
    if(StackTop == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(){
    int data = 0;
    if(StackTop == maxSize - 1) {
        printf("Stack overflow\n");
        return;
    }   
    else{
        printf("Enter the data : \n");
        scanf("%d",&data);
        StackTop++;
        arr[StackTop] = data;
    }
}

void pop(){
    if(isEmpty()){
        printf("Stack underflow.\n");
    }
    else
    StackTop--;
}

void top(){
    if(isEmpty()){
        printf("Can't Get the top as Stack is Empty\n");
        return;
    }
    else
        printf("%d\n", arr[StackTop]);
}

void size(){
       printf("%d\n",StackTop + 1);
}
int main(){
    while(1){
    printf("Enter the size of stack: ");
    scanf("%d", &maxSize);
    if(maxSize<=0){
        printf("Enter a valid positive integer for the size.\n");
        }
    else
        break;
    }
    arr=NULL;
    arr = (int*)malloc(maxSize * sizeof(int));
    while(choice!=6){
        printf("Stack operations are:\n");
        printf("1. Add an element to the stack.\n");
        printf("2. Remove the top element from the stack.\n");
        printf("3. Retrieve the top element without removing it.\n");
        printf("4. Check if the stack is empty.\n");
        printf("5. Return the number of elements in the stack.\n");
        printf("6. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1: 
                push();
                break;
                
            case 2: 
                pop();
                break;
                
            case 3: 
                top();
                break;
                
            case 4:
                isEmpty() ? printf("Stack is Empty.\n") : printf("Not Empty.\n");
                break;
                
            case 5:
                size();
                break;
                
            case 6:
                printf("Exiting\n");
                break;
                
            default:
                printf("Enter a valid choice: \n");
            
        }
    }
    free(arr);
    return 0;
}