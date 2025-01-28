#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* findMid(struct Node* head) {
    struct Node* fast = head;
    struct Node* slow = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        if (fast != NULL) {
            slow = slow->next;
        }
    }

    struct Node* temp = slow->next;
    slow->next = NULL;
    return temp;
}

void deleteDuplicates(struct Node* head){
    if (head == NULL) return ;

    struct Node* current = head;

    while (current != NULL && current->next != NULL) {
      if (current->data == current->next->data) {
        current->next = current->next->next;
      } else {
        current = current->next;
      }
    }

}
struct Node* merge(struct Node* first, struct Node* second) {
  
    if (first == NULL) return second;
    if (second == NULL) return first;

    if (first->data < second->data) {
        first->next = merge(first->next, second);
        return first;
    }
    else {
        second->next = merge(first, second->next);
        return second;
    }
}

struct Node* MergeSort(struct Node* head) {
  
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node* second = findMid(head);

    head = MergeSort(head);
    second = MergeSort(second);

    return merge(head, second);
}

void printList(struct Node* head) {
    struct Node* temp = head;
    if(head == NULL){
        printf("List is empty.\n");
    }
    while(temp!=NULL){
        if(temp->next!=NULL){
            printf("%d->",temp->data);
        }
        else{
            printf("%d", temp->data);
        }
        temp = temp->next;
    }
    printf("\n");
}

struct Node* createNode(int value) {
    struct Node* newNode = 
      (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(int value){
    struct Node* newNode = createNode(value);
    struct Node* temp = head;
    if(head == NULL){
        head = newNode;
    }
    else{
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main() {
   int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        insertAtEnd(arr[i]);
    }

    head = MergeSort(head);
    printf("The linked list after removing duplicates is:\n");
    deleteDuplicates(head);
    printList(head);

    return 0;
}
