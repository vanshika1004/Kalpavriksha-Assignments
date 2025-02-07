#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define tableSize 10

typedef struct node {
    int key;
    int value;
    struct node *next;
} node;

node **hashMap;

void intializeHashMap(node ***hashMap) {
    *hashMap = (node **)malloc(sizeof(node *) * tableSize);
    for (int index = 0; index < tableSize; index++) {
        (*hashMap)[index] = NULL;
    }
}

int hashFunction(int key) {
    return key % tableSize;
}

node* createNode(int key, int value) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insert(node **hashMap) {
    int key = 0, value = 0;
    // checking for valid key
    while(1){
            printf("Enter the key: ");
            scanf("%d", &key);
            if(key < 0){
                printf("Enter valid positive integers for key.\n");
            }
            else{
                break;
            }
    }
    // checking for valid value
    while(1){
            printf("Enter the value: ");
            scanf("%d", &value);
            if(value < 0){
                printf("Enter valid positive integers for value.\n");
            }
            else{
                break;
            }
    }
    int bucketIndex = hashFunction(key);
    node* current = hashMap[bucketIndex];
    
    // Check if the key is present
    while (current != NULL) {
        if (current->key == key) {
            current->value = value;
            printf("Key %d updated with value %d\n", key, value);
            return;
        }
        current = current->next;
    }

    node* newNode = createNode(key, value);
    if (hashMap[bucketIndex] == NULL) {
        hashMap[bucketIndex] = newNode;
    } else {
        node* temp = hashMap[bucketIndex];
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void delete(node **hashMap) {
    int key = 0;
    while(1){
            printf("Enter the key: ");
            scanf("%d", &key);
            if(key < 0){
                printf("Enter valid positive integers for key.\n");
            }
            else{
                break;
            }
    }

    int bucketIndex = hashFunction(key);

    node* prevNode = NULL;
    node* currNode = hashMap[bucketIndex];

    while (currNode != NULL) {
        if (key == currNode->key) {
            if (currNode == hashMap[bucketIndex]) {
                hashMap[bucketIndex] = currNode->next;
            } else {
                prevNode->next = currNode->next;
            }
            free(currNode);
            printf("Key %d deleted successfully\n", key);
            return;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
    printf("Key %d not found.\n", key);
}

void search(node **hashMap) {
    int key = 0;
    while(1){
            printf("Enter the key: ");
            scanf("%d", &key);
            if(key < 0){
                printf("Enter valid positive integers for key.\n");
            }
            else{
                break;
            }
    }
    int bucketIndex = hashFunction(key);

    node* bucketHead = hashMap[bucketIndex];
    while (bucketHead != NULL) {
        if (bucketHead->key == key) {
            printf("Value: %d\n", bucketHead->value);
            return;
        }
        bucketHead = bucketHead->next;
    }

    printf("Key %d not found.\n", key);
}

void display(node **hashMap) {
    printf("Hash Table:\n");
    for (int i = 0; i < tableSize; i++) {
        node* current = hashMap[i];
        if (current != NULL) {
            printf("Index %d: ", i);
            while (current!= NULL) {
                if(current->next!=NULL){
                    printf("(%d, %d) -> ", current->key, current->value);
                }
                else{
                    printf("(%d, %d)", current->key, current->value);
                }
                current = current->next;
            }
            printf("\n");
        }
    }
    printf("\n");
}

void freeHashMap(node **hashMap) {
    for (int i = 0; i < tableSize; i++) {
        node* current = hashMap[i];
        while (current != NULL) {
            node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hashMap);
}

int main() {
    int choice = 0;
    intializeHashMap(&hashMap);

    printf("Hashmap functions are:-\n");
    printf("1. Insert (Put)\n");
    printf("2. Search (Get)\n");
    printf("3. Delete (Remove)\n");
    printf("4. Display\n");
    printf("5. Exit\n");

    while (choice != 5) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                insert(hashMap);
                printf("\n");
                break;
                
            case 2:
                search(hashMap);
                printf("\n");
                break;
                
            case 3:
                delete(hashMap);
                printf("\n");
                break;
                
            case 4:
                display(hashMap);
                printf("\n");
                break;
                
            case 5:
                printf("Exiting program.\n");
                break;
                
            default:
                printf("Enter a valid choice\n");
        }
    }

    freeHashMap(hashMap);
    return 0;
}
