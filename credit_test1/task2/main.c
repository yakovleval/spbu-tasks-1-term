#include <stdio.h>
#include "../../hw6/6.3/mergesort.h"
#include "../../hw6/6.3/product.h"

int main() {
    Product *list = NULL;
    Error err = loadList(&list, "storage.txt");
    if (err != 0) {
        printf("unexpected error occured\n");
        freeList(list);
        return 0;
    }
    printf("enter n and m:\n");
    int n, m;
    scanf("%d%d", &n, &m);
    while (n < 0 || m < 0) {
        printf("incorrect input, try again:\n");
        scanf("%d%d", &n, &m);
    }
    mergeSort(&list, NUMBER, DESCENDGING);
    int listLength = listLen(&list);
    n = n < listLength ? n : listLength;
    Product **current = &list;
    printf("products with 50%% sale:\n");
    for (int i = 0; i < n; i++) {
        printProduct(*current);
        deleteProduct(current);
    }
    listLength = listLen(&list);
    m = m < listLength ? m : listLength;
    current = &list;
    mergeSort(&list, NAME, ASCENDING);
    printf("products with 25%% sale:\n");
    for (int i = 0; i < m; i++) {
        printProduct(*current);
        deleteProduct(current);
    }
    printf("products with no sale:\n");
    for (current = &list; *current != NULL;) {
        printProduct(*current);
        deleteProduct(current);
    }
    return 0;
}
