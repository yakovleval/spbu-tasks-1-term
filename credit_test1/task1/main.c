#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 257
#define BASE 3

int main() {
    char buffer[BUFFER_SIZE];
    printf("enter the string:\n");
    scanf("%256s", buffer);
    int length = strlen(buffer);
    int start = 0;
    while (start < length && buffer[start] == '0')
        start++;
    if (start == length) {
        printf("0\n");
        return 0;
    }
    if ((length - start) % BASE == 1) {
        printf("%d", buffer[start] - '0');
        start++;
    }
    else if ((length - start) % BASE == 2){
        printf("%d", (buffer[start] - '0') * 2 + buffer[start + 1] - '0');
        start += 2;
    }
    for (int i = start; i < length; i += BASE) {
        printf("%d", (buffer[i] - '0') * 4 +
                     (buffer[i + 1]- '0') * 2 +
                     buffer[i + 2] - '0');
    }
    return 0;
}
