#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "headers/structure.h"

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

        while (currentNode->next != NULL) {
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