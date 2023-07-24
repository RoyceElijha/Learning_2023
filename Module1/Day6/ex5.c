#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int marks;
};

void searchByName(struct Student arr[], int size, const char* name) {
    int i, found = 0;

    for (i = 0; i < size; i++) {
        if (strcmp(arr[i].name, name) == 0) {
            printf("Student found:\n");
            printf("Name: %s\n", arr[i].name);
            printf("Marks: %d\n", arr[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

int main() {
    int i, num;
    char searchName[50];

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

    printf("\nEnter the name to search: ");
    scanf("%s", searchName);


    searchByName(students, num, searchName);

    return 0;
}

