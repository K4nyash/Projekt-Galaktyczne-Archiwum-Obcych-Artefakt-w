#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "headers/structure.h"
#include "headers/sorting.h"
#include "headers/searching.h"
#include "headers/fileHandling.h"


void TestData(struct Node** head) {
    InsertData(head, "Krysztal Harmonii", "Kepler-186f", "Thal kari", 1, 2465, "bezpieczny");
    InsertData(head, "Ostrze Pustki", "Sektor 9", "Nieznana", 10, 2470, "zakazany");
    InsertData(head, "Chronometr Pradawnych", "Mars", "Prekursorzy", 2, 2399, "w trakcie badan");
    InsertData(head, "Zarodnik Hivemind", "Xenon Prime", "Roj", 9, 2470, "wymaga kwarantanny");
    InsertData(head, "Rdzen Energetyczny Mk-IV", "Wrak Stacji Alfa", "Imperium Ludzkosci", 6, 2450, "niestabilny");
    InsertData(head, "Maska Zlotego Switu", "Proxima Centauri b", "Aurorianie", 0, 2410, "bezpieczny");
    InsertData(head, "Szepczaca Kula", "Mglawica Oriona", "Nieznana", 8, 2468, "wymaga kwarantanny");
    InsertData(head, "Tabliczka Gwiezdnych Map", "Ksiezyc Tytan", "Cywilizacja typu II", 2, 2405, "w trakcie badan");
    InsertData(head, "Generator Osobliwosci", "Sektor Omega", "Zaginieni Architekci", 10, 2470, "zakazany");
    InsertData(head, "Plynne Lustro", "Gliese 667 Cc", "Wedrowcy", 5, 2460, "niestabilny");
}

int main() {
    struct Node* head = NULL;
    char choice;
    int isRunning = 1;
    int size = 0;

    //Dodawanie danych testowych
    TestData(&head);
    size = 10;
    
    while(isRunning == 1){
        printf("\n=== GALAKTYCZNE ARCHIWUM OBCYCH ARTEFAKTOW ===\n");
        printf("1. Rejestracja nowego artefaktu\n");
        printf("2. Wyswietl katalog\n");
        printf("3. Wyszukiwanie\n");
        printf("4. Sortowanie\n");
        printf("5. Edycja danych artefaktu\n");
        printf("6. Usuniecie artefaktu\n");
        printf("7. Zapis do pliku\n");
        printf("8. Odczyt z pliku\n");        
        printf("0. Wyjscie\n");
        printf("==============================================\n");
        printf("Wybór: ");
        choice = fgetc(stdin);
        while ( getchar() != '\n' );

        switch (choice) {
            case '1':
                Insert(&head);
                size++;
                break;
            case '2':
                Print(head);
                break;
            case '3':
                Search(head, size);
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
            case '7':
                SaveToFile(head);
                break;
            case '8':
                LoadFromFile(&head);
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