#include <stdio.h>

void printNumbers(int n) {
    int i;
    for (i = 1; i <= n; i++) {
        printf("%d", i);
    }
}

void printSpaces(int n) {
    int i;
    for (i = 1; i <= n; i++) {
        printf(" ");
    }
}

void printReverseNumbers(int n) {
    int i;
    for (i = n; i >= 1; i--) {
        printf("%d", i);
    }
}

int main() {
    int n, i;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (i = n; i >= 1; i--) {
        printNumbers(i);
        printSpaces(2 * (n - i));
        printReverseNumbers(i);
        printf("\n");
    }

    return 0;
}

