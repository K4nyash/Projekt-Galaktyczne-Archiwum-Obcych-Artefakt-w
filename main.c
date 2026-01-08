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
        printf("Lista jest pusta\n");
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
        printf("Lista jest pusta\n");
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
        printf("Pozycja poza zakresem\n");
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
        printf("Pozycja poza zakresem\n");
        return;
    }
    strcpy(temp->name, name);
    strcpy(temp->origin, origin);
    strcpy(temp->creatorCiv, creatorCiv);
    temp->dangerLevel = dangerLevel;
    temp->discoveryYear = discoveryYear;
    strcpy(temp->status, status);

}

void SwapNodes(struct Node *a, struct Node *b) {
    char tempName[100];
    char tempOrigin[30];
    char tempCreator[50];
    char tempStatus[30];
    int tempDanger;
    int tempYear;

    strcpy(tempName, a->name);
    strcpy(tempOrigin, a->origin);
    strcpy(tempCreator, a->creatorCiv);
    tempDanger = a->dangerLevel;
    tempYear = a->discoveryYear;
    strcpy(tempStatus, a->status);

    strcpy(a->name, b->name);
    strcpy(a->origin, b->origin);
    strcpy(a->creatorCiv, b->creatorCiv);
    a->dangerLevel = b->dangerLevel;
    a->discoveryYear = b->discoveryYear;
    strcpy(a->status, b->status);

    strcpy(b->name, tempName);
    strcpy(b->origin, tempOrigin);
    strcpy(b->creatorCiv, tempCreator);
    b->dangerLevel = tempDanger;
    b->discoveryYear = tempYear;
    strcpy(b->status, tempStatus);
}

void Sort(struct Node *head) {
    if (head == NULL) {
        printf("Lista jest pusta, nie można posortować\n");
        return;
    }

    int sortChoice;
    printf("\n===== OPCJE SORTOWANIA =====\n");
    printf("1. Po Nazwie Artefaktu\n");
    printf("2. Po Pochodzeniu\n");
    printf("3. Po Cywilizacji Tworców\n");
    printf("4. Po Poziomie Zagrozenia\n");
    printf("5. Po Roku Odkrycia \n");
    printf("6. Po Statusie Artefaktu\n");
    printf("============================\n");
    printf("Wybór: ");
    scanf("%d", &sortChoice);
    while (getchar() != '\n');

    if (sortChoice < 1 || sortChoice > 6) {
        printf("Nieprawidlowy wybór sortowania\n");
        return;
    }

    int swapped;
    struct Node *currentNode;
    struct Node *lastSortedNode = NULL;

    do {
        swapped = 0;
        currentNode = head;

        while (currentNode->next != lastSortedNode) {
            int shouldSwap = 0;

            switch (sortChoice) {
                case 1:
                    if (strcmp(currentNode->name, currentNode->next->name) > 0) {
                        shouldSwap = 1;
                    }
                    break;
                case 2:
                    if (strcmp(currentNode->origin, currentNode->next->origin) > 0) {
                        shouldSwap = 1;
                    }
                    break;
                case 3:
                    if (strcmp(currentNode->creatorCiv, currentNode->next->creatorCiv) > 0) {
                        shouldSwap = 1;
                    }
                    break;
                case 4:
                    if (currentNode->dangerLevel > currentNode->next->dangerLevel) { 
                        shouldSwap = 1;
                    }
                    break;
                case 5:
                    if (currentNode->discoveryYear > currentNode->next->discoveryYear) {
                        shouldSwap = 1;
                    }
                    break;
                case 6:
                    if (strcmp(currentNode->status, currentNode->next->status) > 0) {
                        shouldSwap = 1;
                    }
                    break;
            }

            if (shouldSwap) {
                SwapNodes(currentNode, currentNode->next);
                swapped = 1;
            }
            currentNode = currentNode->next;
        }
        lastSortedNode = currentNode;

    } while (swapped == 1);

    printf("Archiwum zostało posortowane\n");
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

void TestData(struct Node** head) {
    InsertData(head, "Krysztal Harmonii", "Kepler-186f", "Thal kari", 1, 2465, "bezpieczny");
    InsertData(head, "Ostrze Pustki", "Sektor 9", "Nieznana", 10, 2470, "zakazany");
    InsertData(head, "Chronometr Pradawnych", "Mars", "Prekursorzy", 4, 2399, "w trakcie badan");
    InsertData(head, "Zarodnik Hivemind", "Xenon Prime", "Roj", 9, 2471, "wymaga kwarantanny");
    InsertData(head, "Rdzen Energetyczny Mk-IV", "Wrak Stacji Alfa", "Imperium Ludzkosci", 6, 2450, "niestabilny");
    InsertData(head, "Maska Zlotego Switu", "Proxima Centauri b", "Aurorianie", 0, 2410, "bezpieczny");
    InsertData(head, "Szepczaca Kula", "Mglawica Oriona", "Nieznana", 8, 2468, "wymaga kwarantanny");
    InsertData(head, "Tabliczka Gwiezdnych Map", "Ksiezyc Tytan", "Cywilizacja typu II", 2, 2405, "w trakcie badan");
    InsertData(head, "Generator Osobliwosci", "Sektor Omega", "Zaginieni Architekci", 10, 2471, "zakazany");
    InsertData(head, "Plynne Lustro", "Gliese 667 Cc", "Wedrowcy", 5, 2460, "niestabilny");
}





int main() {
    struct Node* head = NULL;
    char choice;
    int isRunning = 1;

    //Dodawanie danych testowych
    TestData(&head);
    
    while(isRunning == 1){
        printf("\n=== GALAKTYCZNE ARCHIWUM OBCYCH ARTEFAKTOW ===\n");
        printf("1. Rejestracja nowego artefaktu\n");
        printf("2. Wyswietl katalog\n");
        printf("3. Wyszukiwanie\n");
        printf("4. Sortowanie\n");
        printf("5. Edycja danych artefaktu\n");
        printf("6. Usuniecie artefaktu\n");
        printf("0. Wyjscie\n");
        printf("==============================================\n");
        printf("Wybór: ");
        choice = fgetc(stdin);
        while ( getchar() != '\n' );

        switch (choice) {
            case '1':
                Insert(&head);
                break;
            case '2':
                Print(head);
                break;
            case '3':
                break;
            case '4':
                Sort(head);
                break;
            case '5':
                Update(&head);
                break;
            case '6':
                Delete(&head);
                break;
            case '0':
                isRunning = 0;
                break;
            default:
                printf("Nieprawidłowy wybór\n");
                break;
        }
    }

  return 0;
} 