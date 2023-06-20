#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(const char *input, struct Student *students, int size) {
    char temp[100];
    strcpy(temp, input);
    char *token = strtok(temp, " ");

    if (token != NULL)
        students->rollno = atoi(token);

    token = strtok(NULL, " ");

    if (token != NULL)
        strcpy(students->name, token);

    token = strtok(NULL, " ");

    if (token != NULL)
        students->marks = atof(token);
}

void displayStudents(struct Student *students, int size) {
    printf("Student Details:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("--------------------\n");
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    getchar();  

    struct Student *students = (struct Student *)malloc(numStudents * sizeof(struct Student));

    for (int i = 0; i < numStudents; i++) {
        char input[100];
        printf("\nEnter the details for student %d: ", i + 1);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        parseString(input, &students[i], sizeof(struct Student));
    }

    printf("\n");

    displayStudents(students, numStudents);

    free(students);

    return 0;
}

