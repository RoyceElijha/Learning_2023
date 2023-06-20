#include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeStudents(struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter details for Student %d:\n", i + 1);
        
        printf("Roll Number: ");
        scanf("%d", &(students[i].rollno));
        
        printf("Name: ");
        scanf("%s", students[i].name);
        
        printf("Marks: ");
        scanf("%f", &(students[i].marks));
        
        printf("\n");
    }
}

void displayStudents(const struct Student* students, int size) {
    printf("Details of Students:\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    int size;
    
    printf("Enter the number of students: ");
    scanf("%d", &size);
    
    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));
    
    if (students == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    initializeStudents(students, size);
    
    displayStudents(students, size);
    
    free(students);
    
    return 0;
}

