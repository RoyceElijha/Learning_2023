#include <stdio.h>

int stringToInteger(const char str[]) {
    int result = 0;
    int sign = 1;
    int i = 0;

    // Handle the sign (if any)
    if (str[0] == '-') {
        sign = -1;
        i = 1;
    }

    // Convert each digit to an integer and accumulate the result
    while (str[i] != '\0') {
        int digit = str[i] - '0';  // Convert character to integer
        result = result * 10 + digit;
        i++;
    }

    return sign * result;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int number = stringToInteger(str);

    printf("Converted integer: %d\n", number);

    return 0;
}

