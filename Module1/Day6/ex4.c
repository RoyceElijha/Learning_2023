#include <stdio.h>

struct Student {
    char name[50];
    int marks;
};

void sortArray(struct Student arr[], int size) {
    int i, j;
    struct Student temp;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j].marks < arr[j + 1].marks) {
                // Swap the elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int i, num;

    printf("Enter the number of students: ");
    scanf("%d", &num);

    struct Student students[num];


    for (i = 0; i < num; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%d", &students[i].marks);
    }


    sortArray(students, num);

    printf("\nStudents in descending order of marks:\n");
    for (i = 0; i < num; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Marks: %d\n", students[i].marks);
        printf("\n");
    }

    return 0;
}

