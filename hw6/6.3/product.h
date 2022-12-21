#ifndef INC_6_3_PRODUCT_H
#define INC_6_3_PRODUCT_H

#define MAX_SIZE 256

typedef int Error;

typedef struct Product {
    char name[MAX_SIZE];
    int number;
    struct Product *next;
} Product;

int listLen(Product **iterator);

Error loadList(Product **iterator, const char *file);

Error addPerson(Product **iterator, const char *name, const char *number);

void printList(Product **iterator);

Product *findByNumber(Product **iterator, const char *number);

Product *findByName(Product **iterator, const char *name);

void saveList(Product **iterator);

void freeList(Product *iterator);

Product **next(Product **current);

void printProduct(Product *current);

void deleteProduct(Product **product);

#endif //INC_6_3_PRODUCT_H
