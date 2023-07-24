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

ComplexNumber pop(ComplexStack *stack) {
    ComplexNumber complexNum;

    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
        complexNum.real = 0.0;
        complexNum.imaginary = 0.0;
    } else {
        complexNum = stack->arr[stack->top];
        stack->top--;
    }

    return complexNum;
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

    ComplexNumber poppedNum = pop(&stack);
    printf("Popped Complex Number: %.2lf + %.2lfi\n", poppedNum.real, poppedNum.imaginary);

    return 0;
}

