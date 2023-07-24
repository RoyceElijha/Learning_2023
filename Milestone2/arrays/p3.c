#include <stdio.h>

void sortArray(int arr[], int N, int order) {
    
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if ((arr[j] > arr[j + 1] && order == 1) || (arr[j] < arr[j + 1] && order == -1)) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
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

    int order;
    printf("Enter the order (1 for ascending, -1 for descending): ");
    scanf("%d", &order);

    sortArray(arr, N, order);

    printf("Sorted Array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

