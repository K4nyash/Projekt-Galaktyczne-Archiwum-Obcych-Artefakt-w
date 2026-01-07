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
    scanf("%d", &dangerLevel);
    while ( getchar() != '\n' );

    printf("Podaj rok odkrycia artefaktu: ");
    scanf("%d", &discoveryYear);
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

void DeleteFromFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
}

void Delete(struct Node** head) {

    int position;

    printf("Podaj pozycje do usuniecia: ");
    scanf("%d", &position);
    while ( getchar() != '\n' );

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    if (position == 0) {
        DeleteFromFirst(head);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
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

    printf("Podaj pozycje do zmiany: ");
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
    scanf("%d", &dangerLevel);
    while ( getchar() != '\n' );

    printf("Podaj rok odkrycia artefaktu: ");
    scanf("%d", &discoveryYear);
    while ( getchar() != '\n' );

    printf("Podaj status artefaktu: ");
    fgets(status, sizeof(status), stdin);
    status[strcspn(status, "\n")] = 0;

    if (*head == NULL) {
        printf("List is empty\n");
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
        printf("Position out of range\n");
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
        printf("Lista jest pusta");
    }
    printf("\n%100s", "Nazwa");
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
    char choice;
    int isRunning = 1;
    
    while(isRunning == 1){
        printf("\n=== GALAKTYCZNE ARCHIWUM OBCYCH ARTEFAKTOW (Rok 2471) ===\n");
        printf("1. Rejestracja nowego artefaktu\n");
        printf("2. Wyswietl katalog\n");
        printf("3. Wyszukiwanie\n");
        printf("4. Sortowanie\n");
        printf("5. Edycja danych artefaktu\n");
        printf("6. Usuniecie artefaktu\n");
        printf("7. Zapisz zmiany do pliku\n");
        printf("0. Wyjscie\n");
        printf("=========================================================\n");
        printf("Wybor: ");
        choice = fgetc(stdin);
        while ( getchar() != '\n' );
        switch (choice)
        {
        case '1':
            Insert(&head);
            break;
        case '2':
            Print(head);
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            Update(&head);
            break;
        case '6':
            Delete(&head);
            break;
        case '7':
            break;
        case '0':
            isRunning = 0;
            break;
        default:
            printf("Nieprawidlowy wybor\n");
            break;
        }
    }

  return 0;
} 