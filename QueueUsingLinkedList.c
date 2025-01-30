#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *rear = NULL,*front = NULL;
int queueSize = 0;

struct node* createNode(int value){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
    return NULL;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(){
    if(front == NULL){
        return 1;
    }   
    else{
        return 0;
    }
}

void enqueue(){
    int value = 0;
    printf("Enter the value: ");
    scanf("%d",&value);
    struct node* newNode = createNode(value);
    if(front == NULL){
        front = newNode;
        rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
    queueSize +=1 ;
}

void dequeue(){
    if(front == NULL){
        printf("Queue is Empty.\n");
        return;
    }    
    struct node* temp = front;
    int element = temp->data;
    front = front->next;
    free(temp);
    printf("%d deleted successfully.\n",element);
    queueSize -= 1;
}

void peek(){
    if(front == NULL){
        printf("Queue is empty.\n");
        return;
    }    
    printf("%d is the top element.\n",front->data);
}

void size(){

    printf("Size of queue is %d\n",queueSize);
}

// void display(){
//     struct node* temp = front;
//     if(temp == NULL) {
//         printf("Queue is empty.\n");
//         return;
//     }
//     printf("Queue elements: ");
//     while(temp != NULL){
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     printf("\n");
// }

void freeMemory(){
    struct node* temp = NULL;
    while(front!=NULL){
        temp = front;
        front = front->next;
        free(temp);
    }
    rear = NULL;
    printf("Memory freed successfully.\n");
}

int main(){
    
    int choice = 0;
    do{
        printf("Queue operations are:\n");
        printf("1. Add an element to the queue.\n");
        printf("2. Remove the top element from the queue.\n");
        printf("3. Retrieve the top element without removing it.\n");
        printf("4. Check if the queue is empty.\n");
        printf("5. Return the number of elements in the queue.\n");
        printf("6. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                enqueue();
                break;
            
            case 2:
                dequeue();
                break;
                
            case 3:
                peek();
                break;
            
            case 4:
                isEmpty() ? printf("Queue is empty.\n") : printf("Not empty.\n");
                break;
                
            case 5:
                size();
                break;
                
            case 6:
                printf("Exiting...\n");
                freeMemory();
                break;
                
            default:
                printf("Enter a valid choice.\n");
        }
    }while(choice!=6);
    
    return 0;
}
