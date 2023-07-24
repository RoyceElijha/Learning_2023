#include <stdio.h>
#include <stdlib.h>

typedef struct ComplexNumber {
    double real;
    double imaginary;
    struct ComplexNumber* next;
} ComplexNumberNode;

ComplexNumberNode* addToBeginning(ComplexNumberNode* head, double real, double imaginary) {
    ComplexNumberNode* newNode = (ComplexNumberNode*)malloc(sizeof(ComplexNumberNode));
    newNode->real = real;
    newNode->imaginary = imaginary;
    newNode->next = head;
    return newNode;
}

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

void addInBetween(ComplexNumberNode* prevNode, double real, double imaginary) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL for insertion.\n");
        return;
    }

    ComplexNumberNode* newNode = (ComplexNumberNode*)malloc(sizeof(ComplexNumberNode));
    newNode->real = real;
    newNode->imaginary = imaginary;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
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

    head = addToBeginning(head, 1.5, 2.7);
    head = addToBeginning(head, 3.2, -0.6);
    head = addToEnd(head, -2.1, 4.3);

    printLinkedList(head);

    ComplexNumberNode* secondNode = head->next;
    if (secondNode != NULL) {
        addInBetween(secondNode, -5.0, 1.8);
        printLinkedList(head);
    }

    freeLinkedList(head);

    return 0;
}

