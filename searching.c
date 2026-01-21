#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "headers/structure.h"

void Search(struct Node* head, int size) {

    int column;
    int isFirstIteration = 1;
    char stringQuery[100];
    int intQuery;
    char correctColumns[7] = "123456";
    int isCorrectColumn = 0;

    printf("\n===== OPCJE WYSZUKIWANIA =====\n");
    printf("1. Nazwa Artefaktu\n");
    printf("2. Pochodzenie\n");
    printf("3. Cywilizacja Tworcow\n");
    printf("4. Zagrozenie\n");
    printf("5. Rok Odkrycia\n");
    printf("6. Status Artefaktu\n");
    printf("==============================\n");
    printf("Wybor: ");
    column = fgetc(stdin);
    while ( getchar() != '\n' );

    for (int i=0; i<6; i++){
        if(column == correctColumns[i]){
            isCorrectColumn = 1;
            break;
        }
    }
    if(isCorrectColumn == 0){
        printf("Nieprawidlowy wybor kolumny.\n");
        return;
    }

    printf("Podaj dane do wyszukiwania: ");
    if (column == '4' || column == '5'){
        scanf("%d", &intQuery);
        while ( getchar() != '\n' );
    }
    else{
        fgets(stringQuery, sizeof(stringQuery), stdin);
        stringQuery[strcspn(stringQuery, "\n")] = 0;
    }

    if (head == NULL){
        printf("Lista jest pusta\n");
        return;
    }

    struct Node* temp = head;

    while (temp != NULL) {

        switch(column){
            case '1':
                if (strstr(temp->name, stringQuery) == NULL) {
                    temp = temp->next;
                    continue;
                }
                break;
            case '2':
                if (strstr(temp->origin, stringQuery) == NULL) {
                    temp = temp->next;
                    continue;
                }
                break;
            case '3':
                if (strstr(temp->creatorCiv, stringQuery) == NULL) {
                    temp = temp->next;
                    continue;
                }
                break;
            case '4':
                if (temp->dangerLevel != intQuery) {
                    temp = temp->next;
                    continue;
                }
                break;
            case '5':
                if (temp->discoveryYear != intQuery) {
                    temp = temp->next;
                    continue;
                }
                break;
            case '6':
                if (strstr(temp->status, stringQuery) == NULL) {
                    temp = temp->next;
                    continue;
                }
                break;
            default:
                printf("Nieprawidlowy wybor kolumny.\n");
                return;
                break;

        }
        if(isFirstIteration == 1){
            printf("\n======================================================== KATALOG OBCYCH ARTEFAKTOW ========================================================\n");
            printf("%-35s", "Nazwa Artefaktu");
            printf("%-25s", "Pochodzenie");
            printf("%-30s", "Cywilizacja Tworcow");
            printf("%-15s", "Zagrozenie");
            printf("%-15s", "Rok Odkrycia");
            printf("%-20s", "Status Artefaktu");
            printf("\n-------------------------------------------------------------------------------------------------------------------------------------------\n");
            isFirstIteration = 0;
        }

        printf("%-35s", temp->name);
        printf("%-25s", temp->origin);
        printf("%-30s", temp->creatorCiv);
        printf("%-15d", temp->dangerLevel);
        printf("%-15d", temp->discoveryYear);
        printf("%-20s\n", temp->status);
        temp = temp->next;
    }
}