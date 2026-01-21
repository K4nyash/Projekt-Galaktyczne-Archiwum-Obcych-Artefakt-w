#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "headers/structure.h"
#include "headers/sorting.h"
#include "headers/searching.h"
#include "headers/fileHandling.h"

int main() {
    struct Node* head = NULL;
    char choice;
    int isRunning = 1;
    int size = 0;
    
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
        printf("Wybor: ");
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
                size += LoadFromFile(&head);
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