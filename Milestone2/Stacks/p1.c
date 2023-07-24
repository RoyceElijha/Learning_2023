#include <stdio.h>

typedef struct {
    double real;
    double imaginary;
} ComplexNumber;

#define MAX_SIZE 100

typedef struct {
    ComplexNumber arr[MAX_SIZE];
    int top;
} ComplexStack;

void initializeStack(ComplexStack *stack) {
    stack->top = -1;
}

int isEmpty(ComplexStack *stack) {
    return stack->top == -1 ? 1 : 0;
}

int isFull(ComplexStack *stack) {
    return stack->top == MAX_SIZE - 1 ? 1 : 0;
}

void push(ComplexStack *stack, ComplexNumber complexNum) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push more elements.\n");
        return;
    }

    stack->top++;
    stack->arr[stack->top] = complexNum;
}

int main() {
    ComplexStack stack;
    initializeStack(&stack);

    ComplexNumber num1 = {2.5, 3.7};
    ComplexNumber num2 = {-1.2, 5.9};
    ComplexNumber num3 = {0.0, -4.1};

    push(&stack, num1);
    push(&stack, num2);
    push(&stack, num3);

    printf("Complex Numbers in the Stack:\n");
    for (int i = stack.top; i >= 0; i--) {
        printf("%.2lf + %.2lfi\n", stack.arr[i].real, stack.arr[i].imaginary);
    }

    return 0;
}

