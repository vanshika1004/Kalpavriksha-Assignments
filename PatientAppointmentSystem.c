#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxSize 15

struct patient {
    int patient_id;
    char severity[maxSize];
    struct patient *next;
};

struct patient *head = NULL;

struct patient* createNode(int id, char *condition) {
    struct patient *newNode = (struct patient*)malloc(sizeof(struct patient));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->patient_id = id;
    strcpy(newNode->severity, condition);
    newNode->next = NULL;
    return newNode;
}

int isDuplicate(int id) {
    struct patient *temp = head;
    while (temp != NULL) {
        if (temp->patient_id == id) {
            return 1; 
        }
        temp = temp->next;
    }
    return 0; 
}

int isValid(char *patient_id){
    int len = strlen(patient_id);
    for(int i = 0;i<len;i++){
        if(patient_id[i]>='0' && patient_id[i]<='9'){
            continue;
        }
        else
        return 0;
    }
    return 1;
}

int stringToInteger(char *str){
    int len = strlen(str);
    int num = 0;
    for(int i = 0;i<len;i++){
        num = num *10+(str[i]-'0');
    }
    return num;
}
void insertAtEnd(int id, char *condition) {
    if (isDuplicate(id)) {
        printf("Patient ID %d is a duplicate. Skipping.\n", id);
        return; 
    }

    if (head == NULL) {
        head = createNode(id, condition);
        return;
    }
    
    struct patient *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = createNode(id, condition);
}

struct patient* findMid(struct patient *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct patient *slow = head;
    struct patient *fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int priority(char *severity) {
    if (strcmp(severity, "Critical") == 0)
        return 1;
    else if (strcmp(severity, "Serious") == 0)
        return 2;
    else if (strcmp(severity, "Stable") == 0)
        return 3;
    else {
        printf("Invalid severity level: %s. Valid options are Critical, Serious & Stable\n", severity);
        return -1;
    }
}

struct patient* merge(struct patient* left, struct patient *right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    struct patient *ans = NULL;
    if (priority(left->severity) < priority(right->severity) ||
        (priority(left->severity) == priority(right->severity) && left->patient_id < right->patient_id)) {
        ans = left;
        left = left->next;
    } else {
        ans = right;
        right = right->next;
    }

    struct patient *curr = ans;
    while (left != NULL && right != NULL) {
        if (priority(left->severity) < priority(right->severity) ||
            (priority(left->severity) == priority(right->severity) && left->patient_id < right->patient_id)) {
            curr->next = left;
            left = left->next;
        } else {
            curr->next = right;
            right = right->next;
        }
        curr = curr->next;
    }

    if (left != NULL) {
        curr->next = left;
    } else {
        curr->next = right;
    }
    return ans;
}

struct patient* mergeSort(struct patient *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct patient *mid = findMid(head);
    struct patient *left = head;
    struct patient *right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    struct patient *result = merge(left, right);
    return result;
}

void ShowList(struct patient *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct patient *temp = head;
    while (temp != NULL) {
        printf("%d %s\n", temp->patient_id, temp->severity);
        temp = temp->next;
    }
}

int main() {
    char numberOfPatients[1000], patient_id[maxSize];
    int patient_Id = 0 ;
    char severity[maxSize];
    int totalPatients = 0;
    printf("Enter the number of patients:-\n");
    scanf("%s", numberOfPatients);  
    // checking valid number of patients
    while(1){
        if(isValid(numberOfPatients)){
            totalPatients = stringToInteger(numberOfPatients);
            break;
        }
        else{
            printf("Enter valid number of totalPatients\n");
            scanf("%s",numberOfPatients);
        }
    }

    for (int patientIdx = 0; patientIdx < totalPatients; patientIdx++) {
        scanf("%s %s", patient_id, severity);
     // checking valid patient_id
        while(1){
            if(isValid(patient_id)){
                patient_Id = stringToInteger(patient_id);
                break;
            }
            else{
                printf("Enter valid patient_id\n");
                scanf("%s",patient_id);
            }
        }
        // checking valid severity
        while(1){
            if(priority(severity)<0){
                printf("Enter valid severity.\n");
                scanf("%s",severity);
            }
            else{
                break;
            }
        }
        insertAtEnd(patient_Id, severity);
    }

    printf("The list is:\n");
    ShowList(head);

    head = mergeSort(head);

    printf("The list after sorting:\n");
    ShowList(head);

    return 0;
}
