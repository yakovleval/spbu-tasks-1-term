#include "person.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "person.h"

int listLen(Person **iterator) {
    int length = 0;
    while (*iterator != NULL) {
        length++;
        iterator = &(*iterator)->next;
    }
    return length;
}

void loadList(Person **iterator) {
    FILE *in = fopen("data.txt", "r");
    if (in == NULL) {
        return;
    }
    int length = 0;
    fscanf(in, " %d", &length);
    char name[101] = {0};
    char number[101] = {0};
    for (int i = 0; i < length; i++) {
        fscanf(in, "%*d");
        fscanf(in, " %[^\n]", name);
        fscanf(in, " %[^\n]", number);
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
    int index = 1;
    while (*iterator != NULL) {
        printf("%d\n", index);
        index++;
        printf("имя: %s\n", (*iterator)->name);
        printf("номер: %s\n", (*iterator)->number);
        iterator = &(*iterator)->next;
    }
}

Person *findByNumber(Person **iterator, const char *number) {
    while (*iterator != NULL && strcmp((*iterator)->number, number) != 0) {
        iterator = &(*iterator)->next;
    }
    return *iterator;
}

Person *findByName(Person **iterator, const char *name) {
    while (*iterator != NULL && strcmp((*iterator)->name, name) != 0) {
        iterator = &(*iterator)->next;
    }
    return *iterator;
}

void saveList(Person **iterator) {
    FILE *out = fopen("data.txt", "w");
    fprintf(out, "%d\n", listLen(iterator));
    int index = 1;
    while (*iterator != NULL) {
        fprintf(out, "%d\n", index);
        index++;
        fprintf(out, "%s\n", (*iterator)->name);
        fprintf(out, "%s\n", (*iterator)->number);
        iterator = &(*iterator)->next;
    }
    fclose(out);
}

void freeList(Person *iterator) {
    while (iterator != NULL) {
        Person *next = iterator->next;
        free(iterator);
        iterator = next;
    }
}
