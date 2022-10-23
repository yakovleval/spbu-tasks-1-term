#include "person.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int listLen(Person **iterator) {
    int length = 0;
    while (*iterator != NULL) {
        length++;
        iterator = &(*iterator)->next;
    }
    return length;
}

void loadList(Person **iterator, const char *file) {
    FILE *in = fopen(file, "r");
    if (in == NULL) {
        return;
    }
    char name[MAX_SIZE] = {0};
    char number[MAX_SIZE] = {0};
    while (!feof(in)) {
//        fscanf(in, "%*d");
        fscanf(in, " %255[^-]-%255s", name, number);
//        fscanf(in, " %[^\n]", number);
        *iterator = (Person *) malloc(sizeof(Person));
        strcpy((*iterator)->name, name);
        strcpy((*iterator)->number, number);
        (*iterator)->next = NULL;
        iterator = &(*iterator)->next;
    }
    fclose(in);
}

void addPerson(Person **iterator, const char *name, const char *number) {
    while (*iterator != NULL) {
        iterator = &(*iterator)->next;
    }
    *iterator = (Person *) malloc(sizeof(Person));
    strcpy((*iterator)->name, name);
    strcpy((*iterator)->number, number);
    (*iterator)->next = NULL;
}

void printList(Person **iterator) {
    while (*iterator != NULL) {
        printf("%s-%s", (*iterator)->name, (*iterator)->number);
        if ((*iterator)->next != NULL) {
            printf(" -> ");
        }
        iterator = &(*iterator)->next;
    }
    printf("\n");
}

void freeList(Person *iterator) {
    while (iterator != NULL) {
        Person *next = iterator->next;
        free(iterator);
        iterator = next;
    }
}
