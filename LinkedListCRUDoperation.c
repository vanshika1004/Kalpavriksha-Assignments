#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* next;
};
struct Node* head = NULL;

int checkPosition(int position){
    struct Node* temp = head;
    int range=0;
    while(temp!=NULL){
        range++;
        temp = temp->next;
    }
    if(position<=0 || position>range){
        return 0;
    }
    else{
        return 1;
    }
}
void insertAtBeginning(int value){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr==NULL){
        printf("OverFlow\n");
        return;
    }
    else{
        ptr->data = value;
        ptr->next = head;
        head = ptr;
    }
}

void insertAtEnd(int value){
    struct Node* ptr,*temp;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr==NULL){
     printf("OverFlow\n");  
    }
    else{
        ptr->data = value;
        if(head == NULL){
        ptr->next = NULL;
        head = ptr;
        }
        else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = NULL;
        }
    }
}

void insertAtPosition(int position,int value){
    struct Node* ptr,*temp;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr==NULL){
        printf("Overflow\n");
    }
    else{
        ptr->data = value;
        if(head == NULL){
            ptr->next = NULL;
            head = ptr;
        }
        else{
            temp = head;
            if(checkPosition(position)){
                temp = head;
                int i=1;
                while(i<position-1){
                    temp = temp->next;
                    i++;
                }
                ptr->next = temp->next;
                temp->next = ptr;
            }
            else{
                printf("Invalid Position\n");
            }
        }
    }
}

void display(){
    struct Node* temp=head;
    if(head == NULL){
        printf("Can't display\n");
    }
    else{
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}

void updateAtPosition(int position,int value){
    if(checkPosition(position)){
        struct Node* temp = head;
        int i=1;
        while(i!=position){
            temp = temp->next;
            i++;
        }
        temp->data = value;
    }
    else{
        printf("Invalid position\n");
    }
}

void deleteAtBeginning(){
    struct Node* ptr;
    if(head == NULL){
        printf("List is empty\n");
    }
    else{
        ptr = head;
        head = head->next;
        free(ptr);
    }
}

void deleteAtEnd(){
    struct Node *ptr,*ptr1;  
    if(head == NULL)  
    {  
        printf("List is empty\n");  
    }
    else if(head -> next == NULL)  
    {  
        free(head);
        head = NULL;  
    }  
         
    else  
    {  
        ptr = head;  
        while(ptr->next != NULL)  
        {  
            ptr1 = ptr;  
            ptr = ptr ->next;  
        }  
        ptr1->next = NULL;  
        free(ptr);  
    }    
}

void deleteAtPosition(int position){
    struct Node* temp = head,*ptr;
    if(head == NULL){
        printf("List is Empty\n");
    }
    else{
        if(position==1){
            deleteAtBeginning();
        }
        else if(checkPosition(position)){
            int i=1;
            while(i<position-1){
                temp=temp->next;
                i++;
            }
            ptr = temp->next;
            temp->next = temp->next->next;
            free(ptr);
        }
        else{
            printf("Invalid Position\n");
        }
    }
}

int main(){
   
    int n;
    scanf("%d",&n);
    int value=0,position=0;
    while(n!=0){
        int choice=0;
        scanf("%d",&choice);
            switch(choice){
                case 1:
                value=0;
                scanf("%d",&value);
                insertAtEnd(value);
                break;
               
                case 2:
                value =0;
                scanf("%d",&value);
                insertAtBeginning(value);
                break;
               
                case 3:
                position=0,value=0;
                scanf("%d",&position);
                scanf("%d",&value);
                insertAtPosition(position,value);
                break;
               
                case 4:
                display();
                break;
               
                case 5:
                position=0,value=0;
                scanf("%d",&position);
                scanf("%d",&value);
                updateAtPosition(position,value);
                break;
               
                case 6:
                deleteAtBeginning();
                break;
               
                case 7:
                deleteAtEnd();
                break;
               
                case 8:
                position=0;
                scanf("%d",&position);
                deleteAtPosition(position);
                break;
               
                default:
                printf("Please enter a valid choice\n");
            }
        
        n--;
    }
    return 0;
}
