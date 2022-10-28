#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include "tree.h"

bool isPassed() {
    const char *tests[] = {"0", "1", "(- 5 4)", "(* (+ 1 1) 2)", "(* (+ 1 1) (/ 8 (- 5 1)))"};
    const int expected[] = {0, 1, 1, 4, 4};
    bool result = true;
    for (int i = 0; i < sizeof(tests) / sizeof(const char *); i++) {
        Node *root = NULL;
        FILE *out = fopen("test.txt", "w");
        fprintf(out, "%s", tests[i]);
        fclose(out);
        FILE *in = fopen("test.txt", "r");
        buildTree(&root, in);
        fclose(in);
        result &= evaluateTree(root) == expected[i];
        freeTree(root);
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "RU-ru");
    if (!isPassed()) {
        printf("тесты не пройдены\n");
        return 0;
    }
    FILE *in = fopen("file.txt", "r");
    Node *root = NULL;
    buildTree(&root, in);
    fclose(in);
    printTree(root);
    printf("\n");
    printf("%d", evaluateTree(root));
    freeTree(root);
}
