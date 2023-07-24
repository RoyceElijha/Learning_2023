#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 4096

void convertToUpper(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

void convertToLower(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

void convertToSentenceCase(char *str) {
    int isFirstChar = 1;
    while (*str) {
        if (isFirstChar) {
            *str = toupper((unsigned char)*str);
            isFirstChar = 0;
        } else {
            *str = tolower((unsigned char)*str);
        }

        if (*str == '.' || *str == '?' || *str == '!') {
            isFirstChar = 1;
        }

        str++;
    }
}

void copyFile(FILE *source, FILE *destination, char *option) {
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
        if (option == NULL) {
            fwrite(buffer, 1, bytesRead, destination);
        } else if (*option == 'u') {
            convertToUpper(buffer);
            fwrite(buffer, 1, bytesRead, destination);
        } else if (*option == 'l') {
            convertToLower(buffer);
            fwrite(buffer, 1, bytesRead, destination);
        } else if (*option == 's') {
            convertToSentenceCase(buffer);
            fwrite(buffer, 1, bytesRead, destination);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments. Usage: ./cp <option> <source_file> <destination_file>\n");
        return 1;
    }

    char *option = NULL;
    char *sourceFileName = argv[2];
    char *destinationFileName = argv[3];

    if (argc > 3) {
        option = argv[1];
    }

    FILE *sourceFile = fopen(sourceFileName, "rb");
    if (sourceFile == NULL) {
        printf("Failed to open the source file.\n");
        return 1;
    }

    FILE *destinationFile = fopen(destinationFileName, "wb");
    if (destinationFile == NULL) {
        printf("Failed to create the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    copyFile(sourceFile, destinationFile, option);

    fclose(sourceFile);
    fclose(destinationFile);

    printf("File copied successfully.\n");

    return 0;
}

