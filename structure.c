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

void Insert(struct Node** head) {
    char name[100];
    char origin[100];
    char creatorCiv[100];
    int dangerLevel;
    int discoveryYear;
    char status[100];

    printf("\n======== DODAWANIE ARTEFAKTU ========\n");
    printf("Podaj nazwe artefaktu: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Podaj pochodzenie artefaktu: ");
    fgets(origin, sizeof(origin), stdin);
    origin[strcspn(origin, "\n")] = 0;

    printf("Podaj cywilizacje tworcow artefaktu: ");
    fgets(creatorCiv, sizeof(creatorCiv), stdin);
    creatorCiv[strcspn(creatorCiv, "\n")] = 0;

    printf("Podaj poziom zagrozenia artefaktu: ");
    while(1) {
        if (scanf("%d", &dangerLevel) != 1) {
            printf("Bledne dane! Sprobuj ponownie: ");
            while ( getchar() != '\n' );
        } else if (dangerLevel < 0 || dangerLevel > 10) {
            printf("Bledny zakres! Sprobuj ponownie: ");
        } else {
            break;
        }
    }

    printf("Podaj rok odkrycia artefaktu: ");
    while (scanf("%d", &discoveryYear) != 1) {
        printf("Bledne dane! Sprobuj ponownie: ");
        while ( getchar() != '\n' );
    }
    while ( getchar() != '\n' );

    printf("Podaj status artefaktu: ");
    fgets(status, sizeof(status), stdin);
    status[strcspn(status, "\n")] = 0;


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

void InsertData(struct Node** head, char name[], char origin[], char creatorCiv[], int dangerLevel, int discoveryYear, char status[]) {
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


void DeleteFromFirst(struct Node** head) {
    if (*head == NULL) {
        printf("Lista jest pusta\n");
        return;
    }
    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
}

void Delete(struct Node** head) {

    int position;

    printf("\n===== OPCJE USUWANIA =====\n");
    printf("Podaj indeks do usuniecia: ");
    scanf("%d", &position);
    while ( getchar() != '\n' );

    if (*head == NULL) {
        printf("Lista jest pusta\n");
        return;
    }
    struct Node* temp = *head;
    if (position == 0) {
        if(temp->dangerLevel < 8){
            DeleteFromFirst(head);
        }
        else{
            printf("Poziom zagrozenia tego artefaktu jest zbyt wysoki");
        }
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Indeks poza zakresem\n");
        return;
    }
    if(temp->dangerLevel >= 8){
        printf("Poziom zagrozenia tego artefaktu jest zbyt wysoki");
        return;
    }
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void Update(struct Node** head) {

    int position;
    char name[100];
    char origin[100];
    char creatorCiv[100];
    int dangerLevel;
    int discoveryYear;
    char status[100];

    printf("\n======== OPCJE EDYTOWANIA ========\n");
    
    printf("Podaj indeks do zmiany: ");
    scanf("%d", &position);
    while ( getchar() != '\n' );

    printf("Podaj nazwe artefaktu: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Podaj pochodzenie artefaktu: ");
    fgets(origin, sizeof(origin), stdin);
    origin[strcspn(origin, "\n")] = 0;

    printf("Podaj cywilizacje tworcow artefaktu: ");
    fgets(creatorCiv, sizeof(creatorCiv), stdin);
    creatorCiv[strcspn(creatorCiv, "\n")] = 0;

    printf("Podaj poziom zagrozenia artefaktu: ");
    while(1) {
        if (scanf("%d", &dangerLevel) != 1) {
            printf("Bledne dane! Sprobuj ponownie: ");
            while ( getchar() != '\n' );
        } else if (dangerLevel < 0 || dangerLevel > 10) {
            printf("Bledny zakres! Sprobuj ponownie: ");
        } else {
            break;
        }
    }

    printf("Podaj rok odkrycia artefaktu: ");
    while (scanf("%d", &discoveryYear) != 1) {
        printf("Bledne dane! Sprobuj ponownie: ");
        while ( getchar() != '\n' );
    }
    while ( getchar() != '\n' );


    printf("Podaj status artefaktu: ");
    fgets(status, sizeof(status), stdin);
    status[strcspn(status, "\n")] = 0;

    if (*head == NULL) {
        printf("Lista jest pusta\n");
        return;
    }
    struct Node* temp = *head;
    if (position == 0) {
        strcpy(temp->name, name);
        strcpy(temp->origin, origin);
        strcpy(temp->creatorCiv, creatorCiv);
        temp->dangerLevel = dangerLevel;
        temp->discoveryYear = discoveryYear;
        strcpy(temp->status, status);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Indeks poza zakresem\n");
        return;
    }
    strcpy(temp->name, name);
    strcpy(temp->origin, origin);
    strcpy(temp->creatorCiv, creatorCiv);
    temp->dangerLevel = dangerLevel;
    temp->discoveryYear = discoveryYear;
    strcpy(temp->status, status);

}
void Print(struct Node* head) {
    if (head == NULL){
        printf("Lista jest pusta\n");
        return;
    }
    printf("\n======================================================== KATALOG OBCYCH ARTEFAKTOW ========================================================\n");
    printf("%-35s", "Nazwa Artefaktu");
    printf("%-25s", "Pochodzenie");
    printf("%-30s", "Cywilizacja Tworcow");
    printf("%-15s", "Zagrozenie");
    printf("%-15s", "Rok Odkrycia");
    printf("%-20s", "Status Artefaktu");
    printf("\n-------------------------------------------------------------------------------------------------------------------------------------------\n");

    struct Node* temp = head;

    while (temp != NULL) {
        printf("%-35s", temp->name);
        printf("%-25s", temp->origin);
        printf("%-30s", temp->creatorCiv);
        printf("%-15d", temp->dangerLevel);
        printf("%-15d", temp->discoveryYear);
        printf("%-20s\n", temp->status);
        temp = temp->next;
    }
    printf("===========================================================================================================================================\n");
}