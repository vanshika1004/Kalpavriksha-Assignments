#include<stdio.h>
#include<stdlib.h>

struct Users
{
    char name[30];
    int id;
    int age;
};

struct Users user;
FILE *fp=NULL;


void CreateUser() {
    fp = fopen("users.txt", "a+"); 
    if (fp == NULL) {
        puts("Cannot open file");
        return;
    }

    int isUnique = 0; 
    do {
        isUnique = 1; 
        printf("\nEnter user ID: ");
        scanf("%d", &user.id);
        struct Users temp;
        
        rewind(fp);

        while (fscanf(fp, "%d\t%29[^\t]\t%d\n", &temp.id, temp.name, &temp.age) != EOF) {
            if (temp.id == user.id) { 
                isUnique = 0;
                printf("The ID already exists! Please enter a unique ID.\n");
                break;
            }
        }
    } while (!isUnique);

    printf("Enter user name: ");
    scanf(" %[^\n]s", user.name);

    printf("Enter user age: ");
    scanf("%d", &user.age);

    fprintf(fp, "%d\t%s\t\t%d\n", user.id, user.name, user.age);
    printf("\nUser added successfully\n");

    fclose(fp);
}



void ReadUsers(){
    
    fp=fopen("users.txt","r");
    if(fp==NULL){
        puts("Cannot open file");
        return;
    }

    printf("ID\tName\t\t\tAge\n");
    printf("-----------------------------------------\n");
    while(fscanf(fp, "%d\t%29[^\t]\t%d\n", &user.id, user.name, &user.age)!=EOF){
        printf("%d\t%s\t\t %d",user.id,user.name,user.age);
        printf("\n");
    }

    fclose(fp);
}

void UpdateUser(){
    int Id;
    int flag = 0;
    FILE *tempf = fopen("temp.txt","w");
    fp = fopen("users.txt","r");
    if(tempf == NULL || fp == NULL)
    {
        printf("Cannot open file.\n");
        return;
    }
    printf("\tEnter user id: ");
    scanf("%d",&Id);
    while( fscanf(fp, "%d\t%29[^\t]\t%d\n", &user.id, user.name, &user.age) != EOF)
    {
        if(user.id == Id)
        {
            flag = 1;
            printf("\tEnter updated userid : ");
            scanf("%d",&user.id);
            printf("\tEnter updated name  : ");
            fflush(stdin);
            scanf(" %[^\n]s", user.name);
            printf("\tEnter updated Age:");
            scanf("%d",&user.age);
        }
        fprintf(tempf,"%d\t%s\t\t%d\n",user.id,user.name,user.age);
    }
    fclose(fp);
    fclose(tempf);
    if(flag == 1)
    {
        remove("users.txt");
        rename("temp.txt","users.txt");
        printf("User Details are Updated.\n");
    }
    else
    {
        printf("User does not exist.");
        remove("temp.txt");
    }
}

void DeleteUser(){
    int Id;
    int flag = 0;
    FILE *tempf = fopen("temp.txt","w");
    fp = fopen("users.txt","r");
    if(tempf == NULL || fp == NULL)
    {
        printf("Cannot open file.\n");
        return;
    }
    printf("\tEnter user id you want to delete: ");
    scanf("%d",&Id);
    while( fscanf(fp, "%d\t%29[^\t]\t%d\n", &user.id, user.name, &user.age) != EOF)
    {
        if(user.id == Id)
        {
            flag=1;
            continue;
        }
        else{
            fprintf(tempf,"%d\t%s\t\t%d\n",user.id,user.name,user.age);
        }
    }
    fclose(fp);
    fclose(tempf);
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
                CreateUser();
                break;
            case 2:
                ReadUsers();
                break;
            case 3:
                UpdateUser();
                break;
            case 4:
                DeleteUser();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;

}