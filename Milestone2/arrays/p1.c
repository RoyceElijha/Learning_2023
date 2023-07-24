#include <stdio.h>

int findSecondMinimum(int arr[], int N) {
    int min1, min2;

    if (arr[0] < arr[1]) {
        min1 = arr[0];
        min2 = arr[1];
    } else {
        min1 = arr[1];
        min2 = arr[0];
    }

    for (int i = 2; i < N; i++) {
        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2 && arr[i] != min1) {
            min2 = arr[i];
        }
    }

    return min2;
}

int main() {
    int N;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &N);

    int arr[N];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int secondMin = findSecondMinimum(arr, N);
    printf("Second Minimum: %d\n", secondMin);

    return 0;
}
