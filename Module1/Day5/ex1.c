#include <stdio.h>

// Structure definition for a box
struct Box {
    double length;
    double width;
    double height;
};

// Function to calculate the volume of a box
double calculateVolume(struct Box* box) {
    return box->length * box->width * box->height;
}

// Function to calculate the total surface area of a box
double calculateSurfaceArea(struct Box* box) {
    double topBottomArea = 2 * (box->length * box->width);
    double sideArea = 2 * (box->length * box->height);
    double frontBackArea = 2 * (box->width * box->height);

    return topBottomArea + sideArea + frontBackArea;
}

int main() {
    // Create a box structure variable
    struct Box myBox;

    // Prompt the user to enter the dimensions of the box
    printf("Enter the length of the box: ");
    scanf("%lf", &(myBox.length));

    printf("Enter the width of the box: ");
    scanf("%lf", &(myBox.width));

    printf("Enter the height of the box: ");
    scanf("%lf", &(myBox.height));

    // Create a pointer to the box structure
    struct Box* boxPtr = &myBox;

    // Calculate the volume and total surface area using the (*) asterisk and (.) dot operators
    double volume = calculateVolume(&myBox);
    double surfaceArea = calculateSurfaceArea(&myBox);

    // Print the results
    printf("Using (*) asterisk and (.) dot operators:\n");
    printf("Volume of the box: %.2lf\n", volume);
    printf("Total surface area of the box: %.2lf\n", surfaceArea);

    // Calculate the volume and total surface area using the (->) arrow operator
    volume = calculateVolume(boxPtr);
    surfaceArea = calculateSurfaceArea(boxPtr);

    // Print the results
    printf("Using (->) arrow operator:\n");
    printf("Volume of the box: %.2lf\n", volume);
    printf("Total surface area of the box: %.2lf\n", surfaceArea);

    return 0;
}

