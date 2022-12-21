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
    int number;
    while (!feof(in)) {
        fscanf(in, " %255[^-]-%d", name, &number);
        *iterator = (Product *) malloc(sizeof(Product));
        if (*iterator == NULL)
            return 1;
        strcpy((*iterator)->name, name);
        (*iterator)->number = number;
        (*iterator)->next = NULL;
        iterator = &(*iterator)->next;
    }
    fclose(in);
    return 0;
}

Error addPerson(Product **iterator, const char *name, int number) {
    while (*iterator != NULL) {
        iterator = &(*iterator)->next;
    }
    *iterator = (Product *) malloc(sizeof(Product));
    if (*iterator == NULL)
        return 1;
    strcpy((*iterator)->name, name);
    (*iterator)->number = number;
    (*iterator)->next = NULL;
    return 0;
}

void printList(Product **iterator) {
    while (*iterator != NULL) {
        printf("%s-%d", (*iterator)->name, (*iterator)->number);
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

Product **next(Product **current) {
    return &(*current)->next;
}

void printProduct(Product *current) {
    printf("%s - %d\n", current->name, current->number);
}

void deleteProduct(Product **product) {
    Product *toDelete = *product;
    *product = (*product)->next;
    free(toDelete);
}
