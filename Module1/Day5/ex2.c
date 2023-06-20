#include <stdio.h>

// Structure definition for a complex number
struct Complex {
    double real;
    double imag;
};

// Function to read a complex number from the user
struct Complex readComplex() {
    struct Complex c;

    printf("Enter the real part: ");
    scanf("%lf", &(c.real));

    printf("Enter the imaginary part: ");
    scanf("%lf", &(c.imag));

    return c;
}

// Function to write a complex number to the console
void writeComplex(struct Complex c) {
    printf("%.2lf + %.2lfi\n", c.real, c.imag);
}

// Function to add two complex numbers
struct Complex addComplex(struct Complex c1, struct Complex c2) {
    struct Complex sum;

    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;

    return sum;
}

// Function to multiply two complex numbers
struct Complex multiplyComplex(struct Complex c1, struct Complex c2) {
    struct Complex product;

    product.real = c1.real * c2.real - c1.imag * c2.imag;
    product.imag = c1.real * c2.imag + c1.imag * c2.real;

    return product;
}

int main() {
    struct Complex c1, c2;

    printf("Reading the first complex number:\n");
    c1 = readComplex();

    printf("Reading the second complex number:\n");
    c2 = readComplex();

    printf("\n");

    printf("First complex number: ");
    writeComplex(c1);

    printf("Second complex number: ");
    writeComplex(c2);

    printf("\n");

    struct Complex sum = addComplex(c1, c2);
    printf("Sum of the complex numbers: ");
    writeComplex(sum);

    struct Complex product = multiplyComplex(c1, c2);
    printf("Product of the complex numbers: ");
    writeComplex(product);

    return 0;
}
