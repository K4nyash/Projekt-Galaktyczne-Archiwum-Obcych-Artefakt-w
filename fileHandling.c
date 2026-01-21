#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "headers/structure.h"

void SaveToFile(struct Node* head) {
    FILE *file = fopen("baza.txt", "w");
    if (file == NULL) {
        printf("Blad otwarcia pliku do zapisu\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        fprintf(file, "%s;%s;%s;%d;%d;%s\n", temp->name, temp->origin, temp->creatorCiv, temp->dangerLevel, temp->discoveryYear, temp->status);
        temp = temp->next;
    }
    fclose(file);
    printf("Zapisano dane do pliku baza.txt\n");
}

int LoadFromFile(struct Node** head) {
    FILE *file = fopen("baza.txt", "r");
    int size = 0;

    if (file == NULL) {
        printf("Blad otwarcia pliku do odczytu lub plik nie istnieje\n");
        return 0;
    }
    char buffer[512];
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = 0;
        char *name = strtok(buffer, ";");
        char *origin = strtok(NULL, ";");
        char *creatorCiv = strtok(NULL, ";");
        char *dangerStr = strtok(NULL, ";");
        char *yearStr = strtok(NULL, ";");
        char *status = strtok(NULL, ";");

        if (name && origin && creatorCiv && dangerStr && yearStr && status) {
            InsertData(head, name, origin, creatorCiv, atoi(dangerStr), atoi(yearStr), status);
            size++;
        }
    }
    fclose(file);
    printf("Wczytano dane z pliku baza.txt\n");
    return size;
}