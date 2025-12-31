#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Node{
    char name[100];
    char origin[30];
    char creatorCiv[50];
    int dangerLevel;
    int discoveryYear;
    char status[30];
    struct Node *next;
};

struct Node* CreateNode(char name[100], char origin[100], char creatorCiv[100], int dangerLevel, int discoveryYear, char status[100]){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    strcpy(newNode->origin, origin);
    strcpy(newNode->creatorCiv, creatorCiv);
    newNode->dangerLevel = dangerLevel;
    newNode->discoveryYear = discoveryYear;
    strcpy(newNode->status, status);
    newNode->next = NULL;
    return newNode;
}

void Insert(struct Node** head, char name[100], char origin[100], char creatorCiv[100], int dangerLevel, int discoveryYear, char status[100]) {
    struct Node* newNode = CreateNode(name, origin, creatorCiv, dangerLevel, discoveryYear, status);
    if (*head == NULL) { 
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void Print(struct Node* head) {
    if (head == NULL){
        printf("Lista jest pusta");
    }
    printf("%100s", "Nazwa");
    printf("%30s", "Pochodzenie");
    printf("%50s", "Cywilizacja tworcow");
    printf("%10s", "Poz Zag");
    printf("%10s", "Rok Odk");
    printf("%30s", "Satus\n");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%100s", temp->name);
        printf("%30s", temp->origin);
        printf("%50s", temp->creatorCiv);
        printf( "%10d", temp->dangerLevel);
        printf( "%10d", temp->discoveryYear);
        printf("%30s\n", temp->status);
        temp = temp->next;
    }
}

int main() {
  struct Node* head = NULL;
  // Temp

  for(int i=0; i<10; i++){
    Insert(&head, "Nazwa", "Pochodzenie", "Cywilizacja tworcow", 5, 2250, "bezpieczny");
  }
  Print(head);

  return 0;
} 