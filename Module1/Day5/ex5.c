#include <stdio.h>

// Structure definition for a point
struct Point {
    int x;
    int y;
};

// Function to swap the fields of two points using pointers
void swapPoints(struct Point* p1, struct Point* p2) {
    int tempX = p1->x;
    int tempY = p1->y;

    p1->x = p2->x;
    p1->y = p2->y;

    p2->x = tempX;
    p2->y = tempY;
}

int main() {
    // Create two point structures
    struct Point point1 = {3, 4};
    struct Point point2 = {5, 6};

    printf("Before swapping:\n");
    printf("Point 1: x = %d, y = %d\n", point1.x, point1.y);
    printf("Point 2: x = %d, y = %d\n", point2.x, point2.y);

    // Create pointers to the point structures
    struct Point* p1 = &point1;
    struct Point* p2 = &point2;

    // Swap the fields of the points using pointers
    swapPoints(p1, p2);

    printf("\nAfter swapping:\n");
    printf("Point 1: x = %d, y = %d\n", point1.x, point1.y);
    printf("Point 2: x = %d, y = %d\n", point2.x, point2.y);

    return 0;
}

