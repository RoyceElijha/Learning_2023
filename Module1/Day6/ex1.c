#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Student {
    int rollno;
    char name[20];
    float marks;
};


void parseString(const char* input, struct Student* students, int size) {
    int count = sscanf(input, "%d %s %f", &(students->rollno), students->name, &(students->marks));

    if (count != 3) {
        printf("Insufficient input for all structures\n");
        return;
    }
	int i;
    for (i = 1; i < size; i++) {
        students++;
        input = strchr(input, ' ') + 1;
        count = sscanf(input, "%d %s %f", &(students->rollno), students->name, &(students->marks));

        if (count != 3) {
            printf("Insufficient input for all structures\n");
            return;
        }
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

    while (getchar() != '\n')
        ;

    char input[100];
    printf("Enter the string input: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    parseString(input, students, size);

    printf("\nData for %d students:\n", size);
    int i;
    for (i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
    
    free(students);

    return 0;
}

