#include <stdio.h>

void findMaxMin(int arr[], int size, int* max, int* min) {
    *max = arr[0];  // Assume the first element is the maximum
    *min = arr[0];  // Assume the first element is the minimum

    for (int i = 1; i < size; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int max, min;
    findMaxMin(arr, size, &max, &min);
    printf("Maximum value in the array: %d\n", max);
    printf("Minimum value in the array: %d\n", min);

    return 0;
}

