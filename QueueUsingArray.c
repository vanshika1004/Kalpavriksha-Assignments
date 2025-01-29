#include<stdio.h>
#include<stdlib.h>

#define maxSize 100

struct Queue{
    int queue[maxSize];
    int front;
    int rear;
    int currSize ;
};

int isEmpty(struct Queue *q){
    if(q->currSize == 0)
    return 1;
    else
    return 0;
}
void enqueue(struct Queue *q){
    if(q->currSize == maxSize){
        printf("Queue is full.\n");
        return;
    }
    if(q->currSize == 0){
        q->front = 0;
        q->rear = 0;
        }
    else{
        q->rear = (q->rear + 1) % maxSize;
        }
    int data = 0;
    printf("Enter the value:");
    scanf("%d",&data);
    q->queue[q->rear] = data;
    q->currSize+=1;
}

void dequeue(struct Queue *q){
    if(q->currSize == 0){
        printf("Queue is empty.\n");
        return;
    }    
    int element = q->queue[q->front];
    if(q->currSize == 1){
        q->front = -1;
        q->rear = -1;
    }
    else{
        q->front = (q->front + 1) % maxSize;
    }
    q->currSize -= 1;
    printf("%d deleted successfully.\n",element);
}

void peek(struct Queue *q){
    if(q->currSize == 0){
        printf("Queue is Empty.\n");
    }    
    else{
        printf("Top element is %d\n",q->queue[q->front]);
    }
}

void size(struct Queue *q){
    if(isEmpty(q)){
        printf("Size is 0.\n");
        return;
    }
    printf("Size is %d\n",q->currSize);
}

int main(){
    struct Queue q;
    q.front  = -1;
    q.rear = -1;
    q.currSize = 0;
    int choice = 0;
    printf("Queue operations are:\n");
    do{
        
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
                enqueue(&q);
                break;
                
            case 2: 
                dequeue(&q);
                break;
                
            case 3: 
                peek(&q);
                break;
                
            case 4:
                isEmpty(&q) ? printf("Stack is Empty.\n") : printf("Not Empty.\n");
                break;
                
            case 5:
                size(&q);
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
