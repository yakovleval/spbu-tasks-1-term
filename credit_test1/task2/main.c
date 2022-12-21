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
    mergeSort(&list, NUMBER);
    int listLength = listLen(&list);
    n = n < listLength ? n : listLength;
    Product *current = list;
    for (int i = 0; i < n && current != NULL; i++) {
        printProduct(current);
    }
    return 0;
}
