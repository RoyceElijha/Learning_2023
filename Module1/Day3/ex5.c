#include <stdio.h>

void findSmallestLargestDigits(int n, int numbers[]) {
	int i;
    for (i = 0; i < n; i++) {
        int number = numbers[i];
        int smallest = 9;
        int largest = 0;

        
        if (number <= 0) {
            printf("Not Valid\n");
            continue;
        }

        
        while (number > 0) {
            int digit = number % 10;
            if (digit < smallest)
                smallest = digit;
            if (digit > largest)
                largest = digit;
            number /= 10;
        }

        printf("%d: Smallest digit = %d, Largest digit = %d\n", numbers[i], smallest, largest);
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int numbers[n];
    printf("Enter %d numbers: ", n);
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    findSmallestLargestDigits(n, numbers);

    return 0;
}

