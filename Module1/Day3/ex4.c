#include <stdio.h>

int findLargestNumber(int num) {
    int largest = 0;

    int i;
    for( i = 0; i < 4; i++) {
        int divisor = 1000;
        int temp = num;

        int j;
        for (j = 0; j <= i; j++) {
            int digit = temp / divisor;
            temp %= divisor;
            divisor /= 10;
        }

        if (temp > largest) {
            largest = temp;
        }
    }

    return largest;
}

int main() {
    int num;

    printf("Enter a 4-digit number: ");
    scanf("%d", &num);

    int largestNumber = findLargestNumber(num);

    printf("The largest number by deleting a single digit: %d\n", largestNumber);

    return 0;
}

