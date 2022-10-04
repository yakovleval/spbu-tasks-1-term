#ifndef INC_4_3_PERSON_H
#define INC_4_3_PERSON_H

#define MAX_SIZE 256

typedef struct Person {
    char name[MAX_SIZE];
    char number[MAX_SIZE];
    struct Person *next;
} Person;

int listLen(Person **iterator);

void loadList(Person **iterator);

void addPerson(Person **iterator, const char *name, const char *number);

void printList(Person **iterator);

Person *findByNumber(Person **iterator, const char *number);

Person *findByName(Person **iterator, const char *name);

void saveList(Person **iterator);

void freeList(Person *iterator);


#endif //INC_4_3_PERSON_H
