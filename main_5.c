#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  char name[10];
  int age;
  struct Node *next;
};

struct Node* createNode(char name[],int age){
    struct Node *address = malloc(sizeof(struct Node));
    strcpy(address->name,name);
    address -> age = age;
    address -> next = NULL;
    return address;
}

void addNode(struct Node **head,char name[],int age){
    struct Node* newNode = createNode(name,age);
    if(*head == NULL){
        *head = newNode;
        printf("%s\n",newNode->name);
        printf("%d\n\n",newNode->age);
        return;
    }
    struct Node *temp = *head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    printf("%s\n",newNode->name);
    printf("%d\n\n",newNode->age);
}

struct Node *searchNode(struct Node **head,char key[]){
    struct Node *temp = *head;
    while(temp != NULL && strcmp(temp->name, key) != 0){
        temp = temp -> next;
    }
    return temp;
}

void deleteNode(struct Node **head,char key[]){
    struct Node *temp = *head;
    struct Node *prev;
    
    if (strcmp(temp->name, key) == 0) {
        *head = temp->next;   
    }
    while(temp != NULL && strcmp(temp->name,key) != 0){
        prev = temp;
        temp = temp -> next;
    }
    
    if(temp -> next == NULL){
        prev -> next = NULL;
    }
    else{
        prev -> next = temp -> next;
    }
    
    // currect data
    temp = *head;
    while(temp != NULL){
        printf("%s\n",temp->name);
        printf("%d\n\n",temp->age);
        temp = temp->next;
    }
}

int main() {
    struct Node *head = NULL;
    addNode(&head,"vixvify",18);
    addNode(&head,"view",19);
    addNode(&head,"kwan",20);
    addNode(&head,"aon",21);
    addNode(&head,"phu",22);
    
    struct Node *result = searchNode(&head,"view");
    printf("name = %s , age = %d \n\n",result -> name,result -> age);
    
    printf("-------current data-------");
    printf("\n");
    printf("\n");
    
    deleteNode(&head,"vixvify");
    return 0;
}