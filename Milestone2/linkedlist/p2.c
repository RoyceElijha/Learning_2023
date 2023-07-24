#include <stdio.h>
#include <stdlib.h>

typedef struct ComplexNumber {
    double real;
    double imaginary;
    struct ComplexNumber* next;
} ComplexNumberNode;

ComplexNumberNode* addToEnd(ComplexNumberNode* head, double real, double imaginary) {
    ComplexNumberNode* newNode = (ComplexNumberNode*)malloc(sizeof(ComplexNumberNode));
    newNode->real = real;
    newNode->imaginary = imaginary;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    ComplexNumberNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

void printLinkedList(ComplexNumberNode* head) {
    ComplexNumberNode* current = head;
    printf("Linked List of Complex Numbers:\n");
    while (current != NULL) {
        printf("%.2lf + %.2lfi -> ", current->real, current->imaginary);
        current = current->next;
    }
    printf("NULL\n");
}

void freeLinkedList(ComplexNumberNode* head) {
    ComplexNumberNode* current = head;
    ComplexNumberNode* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    ComplexNumberNode* head = NULL;

    head = addToEnd(head, 1.5, 2.7);
    head = addToEnd(head, 3.2, -0.6);
    head = addToEnd(head, -2.1, 4.3);

    printLinkedList(head);
    
    freeLinkedList(head);

    return 0;
}

