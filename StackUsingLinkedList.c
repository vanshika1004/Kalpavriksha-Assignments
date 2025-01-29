#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}node;

int stackSize = 0;
node* head = NULL;

int isEmpty(){
    if(head == NULL)
        return 1;
    else
        return 0;
}

void push(){
    node *newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL){
        printf("Stack overflow.\n");
    }
    else{
        int value = 0;
        printf("Enter the data: ");
        scanf("%d",&value);
        newNode->data = value;
        newNode->next = NULL;
        if(head == NULL){
        head = newNode;
        stackSize = 1;
        }
        else{
        newNode->next = head;
        head = newNode;
        stackSize++;
        }
    }
}

void pop(){
    if(isEmpty()){
        printf("Stack underflow.\n");
        return;
    }
    node *temp = head;
    head = head->next;
    stackSize--;
    free(temp);
    
    if(isEmpty()){
        stackSize = 0;
    }
}

void peek(){
    if(isEmpty()){
        printf("Can't get the top element as the stack is Empty.\n");
        return;
    }  
    printf("The top element of stack is %d\n",head->data);
}

void size(){
    printf("Size of stack is %d\n",stackSize);
}

int main(){
    int choice = 0;
    printf("The Stack Operations using Linked List are:-\n");
    do{
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
                peek();
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
    }while(choice!=6);
    
    return 0;
}
