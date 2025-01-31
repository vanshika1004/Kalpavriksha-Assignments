#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxSize 15

struct node{
    int patient_id;
    char severity[maxSize];
    struct node *next;
};
struct node *head = NULL;

struct node* createNode(int id,char *condition){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->patient_id = id;
    strcpy(newNode->severity,condition);
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(int id,char *condition){
    struct node *newNode = createNode(id,condition);
    if(head == NULL){
        head = newNode;
        return;
    }
    else{
        struct node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

struct node* findMid(struct node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    struct node *slow = head;
    struct node *fast = head->next;

    while(fast!= NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int priority(char *severity){
    if(strcmp(severity, "Critical")==0)
    return 1;
    else if(strcmp(severity,"Serious")==0)
    return 2;
    else
    return 3;
}

struct node* merge(struct node* left,struct node *right){
    if(left==NULL)
    return right;

    if(right == NULL)
    return left;

    struct node *ans = NULL;
    if(priority(left->severity) < priority(right->severity) || (priority(left->severity) == priority(right->severity) && left->patient_id<right->patient_id)){
        ans = left;
        left = left->next;
    }
    else{
        ans = right;
        right = right->next;
    }
    struct node *curr = ans;
    while(left!=NULL && right!=NULL){
        if(priority(left->severity) < priority(right->severity) || (priority(left->severity) == priority(right->severity) && left->patient_id<right->patient_id)){
        curr->next = left;
        curr = left;
        left=left->next;
    }
    else{
        curr->next = right;
        curr = right;
        right=right->next;
    }
    }

    if(left!=NULL){
        curr->next = left;
    }
    else{
        right->next = right;
    }
    return ans;
}

// struct node* merge(struct node* left,struct node *right){
//     if(left==NULL)
//     return right;

//     if(right == NULL)
//     return left;

//     struct node *ans = createNode(-1,"dummy");
//     struct node *curr = ans;
//     while(left!=NULL && right!=NULL){
//         if(priority(left->severity) < priority(right->severity) || (priority(left->severity) == priority(right->severity) && left->patient_id<right->patient_id)){
//         ans->next = left;
//         ans = left;
//         left=left->next;
//     }
//     else{
//         curr->next = right;
//         curr = right;
//         right=right->next;
//     }
//     }

//     if(left!=NULL){
//         curr->next = left;
//     }
//     else{
//         right->next = right;
//     }
//     return ans;
// }
// struct node* mergeSort(struct node *head){
//     // find mid
//     struct node *mid = findMid(head);
//     struct node *left = head;
//     struct node *right = mid->next;
//     mid->next = NULL;

//     left = mergeSort(left);
//     right = mergeSort(right);

//     struct node *result = merge(left,right);
//     return result;
// }
void printList(){
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }
    else{
        struct node *temp = head;
        while(temp!=NULL){
            printf("%d %s",temp->patient_id,temp->severity);
            printf("\n");
            temp = temp->next;
        }
    }
}

int main(){
    int n,patient_id=0;
    char severity[maxSize];

    scanf("%d",&n);
    for(int i = 0 ;i<n;i++){
        scanf("%d %s",&patient_id, severity);
        insertAtEnd(patient_id,severity);
    }
    printf("The list is: .\n");
    printList(head);

    head = mergeSort(head);
    printf("The list after sorting: .\n");
    printList(head);
    return 0;
}
