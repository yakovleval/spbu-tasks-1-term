#ifndef INC_9_1_TABLE_H
#define INC_9_1_TABLE_H
#define HASH_SIZE 10
#include "list.h"
typedef struct Table {
    int size;
    List* table[HASH_SIZE];
} Table;

void add(Table *table, ConstKey word);
double load(Table *table);
double averageLen(Table *table);
int frequency(Table *table, ConstKey key);
void printTable(Table *table);
void freeTable(Table *table);

#endif //INC_9_1_TABLE_H
