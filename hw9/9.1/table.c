#include <stddef.h>
#include <malloc.h>
#include "table.h"
#include "list.h"

int hash(ConstKey key) {
    int result = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        result = (result + key[i]) % HASH_SIZE;
    }
    return result;
}

void add(Table *table, ConstKey word) {
    List **bucket = &table->table[hash(word)];
    List *entry = findEntry(bucket, word);
    if (entry == NULL) {
        addEntry(bucket, word, 1);
        table->size++;
    } else {
        entry->value++;
    }
}

double load(Table *table) {
    return table->size * 1.0 / HASH_SIZE;
}

double averageLen(Table *table) {
    int sum = 0;
    int notEmpty = 0;
    for (int i = 0; i < HASH_SIZE; i++) {
        if (table->table[i] != NULL) {
            sum += length(&table->table[i]);
            notEmpty++;
        }
    }
    return sum * 1.0 / notEmpty;
}

int frequency(Table *table, ConstKey key) {
    List* bucket = table->table[hash(key)];
    List *entry = findEntry(&bucket, key);
    return entry == NULL ? 0 : entry->value;
}

void printTable(Table *table) {
    for (int i = 0; i < HASH_SIZE; i++) {
        printList(table->table[i]);
    }
}

void freeTable(Table *table) {
    for (int i = 0; i < HASH_SIZE; i++) {
        freeList(table->table[i]);
    }
    free(table);
}
