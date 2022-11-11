#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "RU-ru");

    printf("Hello, World!\n");
    return 0;
}
