#ifndef INC_8_1_TREE_H
#define INC_8_1_TREE_H

typedef struct Node Node;
typedef char* Key;
typedef char* Value;
typedef const char* ConstValue;
typedef int Error;

// очищает память выделенную под дерево
void freeTree(Node *root);

// поиск вершины по ключу, возвращает NULL если ключа нет
Node **findNode(Node **root, Key key);

// поиск значения по ключу, возвращает NULL если ключа нет
Value findValue(Node *root, Key key);

// добавляет ключ в дерево, меняет значение существующего
// если ключ уже есть
Error addNode(Node **root, Key key, ConstValue value);

// удаляет ключ из дерева, ничего не делает если ключа нет
void deleteNode(Node **root, int key);

#endif //INC_8_1_TREE_H
