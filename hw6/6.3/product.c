#include "product.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int listLen(Product **iterator) {
    int length = 0;
    while (*iterator != NULL) {
        length++;
        iterator = &(*iterator)->next;
    }
    return length;
}

Error loadList(Product **iterator, const char *file) {
    FILE *in = fopen(file, "r");
    if (in == NULL) {
        return 1;
    }
    char name[MAX_SIZE] = {0};
    char number[MAX_SIZE] = {0};
    while (!feof(in)) {
        fscanf(in, " %255[^-]-%255s", name, number);
        *iterator = (Product *) malloc(sizeof(Product));
        if (*iterator == NULL)
            return 1;
        strcpy((*iterator)->name, name);
        strcpy((*iterator)->number, number);
        (*iterator)->next = NULL;
        iterator = &(*iterator)->next;
    }
    fclose(in);
    return 0;
}

Error addPerson(Product **iterator, const char *name, const char *number) {
    while (*iterator != NULL) {
        iterator = &(*iterator)->next;
    }
    *iterator = (Product *) malloc(sizeof(Product));
    if (*iterator == NULL)
        return 1;
    strcpy((*iterator)->name, name);
    strcpy((*iterator)->number, number);
    (*iterator)->next = NULL;
    return 0;
}

void printList(Product **iterator) {
    while (*iterator != NULL) {
        printf("%s-%s", (*iterator)->name, (*iterator)->number);
        if ((*iterator)->next != NULL) {
            printf(" -> ");
        }
        iterator = &(*iterator)->next;
    }
    printf("\n");
}

void freeList(Product *iterator) {
    while (iterator != NULL) {
        Product *next = iterator->next;
        free(iterator);
        iterator = next;
    }
}

Product *next(Product *current) {
    return current->next;
}

void printProduct(Product *current) {
    printf("current")
}
