#include<stdio.h>
#include<stdlib.h>

struct Users
{
    char name[30];
    int id;
    int age;
};

struct Users user;
FILE *filePointer = NULL;

int checkName(char *name){
    for(int i=0;name[i]!='\0';i++){
        if(!((name[i]>='a' && name[i]<='z') || name[i]>='A' && name[i]<='Z' || name[i]==' ') ){
            return 0;
        }
    }
    return 1;
}

void createUser() {
    filePointer = fopen("users.txt", "a+"); 
    if (filePointer == NULL) {
        puts("Cannot open file");
        return;
    }

    int isUnique = 0; 
    do {
        isUnique = 1; 
        printf("\nEnter user ID: ");
        scanf("%d", &user.id);
        struct Users temp;
        
        rewind(filePointer);

        while (fscanf(filePointer, "%d\t%29[^\t]\t%d\n", &temp.id, temp.name, &temp.age) != EOF) {
            if (temp.id == user.id) { 
                isUnique = 0;
                printf("The ID already exists! Please enter a unique ID.\n");
                break;
            }
        }
    } while (!isUnique);

    while(1){
    printf("Enter user name: ");
    scanf(" %[^\n]s", user.name);
    if(checkName(user.name)){
        break;
    }
    else{
        printf("Enter a valid user name\n");
    }
    }


    while(1){
    printf("Enter user age: ");
    if(scanf("%d",&user.age)!=1 ){
        printf("User age must be a Valid Number.\n");
    }
    else if(user.age<=0){
        printf("Enter a positive number for age.\n");
    }
    else if(!(user.age>=1 && user.age<=130)){
        printf("Enter valid age.\n");
    }
    else{
        break;
    }
    fflush(stdin);
    }

    fprintf(filePointer, "%d\t%s\t\t%d\n", user.id, user.name, user.age);
    printf("\nUser added successfully\n");

    fclose(filePointer);
}



void readUsers(){
    
    filePointer = fopen("users.txt","r");
    if(filePointer == NULL){
        puts("Cannot open file");
        return;
    }

    printf("ID\tName\t\t\tAge\n");
    printf("-----------------------------------------\n");
    while(fscanf(filePointer, "%d\t%29[^\t]\t%d\n", &user.id, user.name, &user.age)!=EOF){
        printf("%d\t%s\t\t %d",user.id,user.name,user.age);
        printf("\n");
    }

    fclose(filePointer);
}

void updateUser(){
    int Id;
    int flag = 0;
    FILE * tempFile = fopen("temp.txt","w");
    FILE * filePointer = fopen("users.txt","r");
    if(tempFile == NULL || filePointer == NULL)
    {
        printf("Cannot open file.\n");
        return;
    }
    printf("\tEnter user id: ");
    scanf("%d",&Id);
    while( fscanf(filePointer, "%d\t%29[^\t]\t%d\n", &user.id, user.name, &user.age) != EOF)
    {
        if(user.id == Id)
        {
            flag = 1;
            int checkId = 0;
            while(!checkId) {
                checkId=1;
                printf("\tEnter updated userid : ");
                scanf("%d",&user.id);

                struct Users temp;
                FILE *tempFilePointer = fopen("users.txt","r");
                while (fscanf(tempFilePointer, "%d\t%29[^\t]\t%d\n", &temp.id, temp.name, &temp.age) != EOF)
                {
                    if (temp.id == user.id)
                    {
                        checkId = 0;
                        printf("Error: ID %d already exists. Please Enter a unique ID.\n", user.id);
                        break;
                    }
                }
                fclose(tempFilePointer);
            }

            while(1){
            printf("Enter user name: ");
            scanf(" %[^\n]s", user.name);
            if(checkName(user.name)){
            break;
            }
            else{
            printf("Enter a valid user name\n");
            }
            }
            
            while(1){
            printf("Enter user age: ");
            if(scanf("%d",&user.age)!=1 ){
            printf("User age must be a Valid Number.\n");
            }
            else if(user.age<=0){
            printf("Enter a positive number for age.\n");
            }
            else if(!(user.age>=1 && user.age<=130)){
            printf("Enter valid age.\n");
            }
            else{
            break;
            }
            fflush(stdin);
            }
        }
        fprintf(tempFile,"%d\t%s\t\t%d\n",user.id,user.name,user.age);
    }
    fclose(filePointer);
    fclose(tempFile);
    if(flag == 1)
    {
        remove("users.txt");
        rename("temp.txt", "users.txt");
        printf("User Details are Updated.\n");
    }
    else
    {
        printf("User does not exist.\n");
        remove("temp.txt");
    }
}

void deleteUser(){
    int Id;
    int flag = 0;
    FILE *tempFile = fopen("temp.txt","w");
    filePointer = fopen("users.txt","r");
    if(tempFile == NULL || filePointer == NULL)
    {
        printf("Cannot open file.\n");
        return;
    }
    printf("\tEnter user id you want to delete: ");
    scanf("%d",&Id);
    while( fscanf(filePointer, "%d\t%29[^\t]\t%d\n", &user.id, user.name, &user.age) != EOF)
    {
        if(user.id == Id)
        {
            flag=1;
            continue;
        }
        else{
            fprintf(tempFile,"%d\t%s\t\t%d\n",user.id,user.name,user.age);
        }
    }
    fclose(filePointer);
    fclose(tempFile);
    if(flag == 1)
    {
        remove("users.txt");
        rename("temp.txt","users.txt");
        printf("User is deleted.\n");
    }
    else
    {
        printf("User does not exist.");
        remove("temp.txt");
    }
}
int main(){

    int choice;
    while (1) {
        
        printf("1. Add User.\n");
        printf("2. Display All the Users.\n");
        printf("3. Update User Detail by ID.\n");
        printf("4. Delete User.\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createUser();
                break;
            case 2:
                readUsers();
                break;
            case 3:
                updateUser();
                break;
            case 4:
                deleteUser();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
