#include <stdio.h>

#define BUFFER_SIZE 4096

int main() {
    FILE *sourceFile, *destinationFile;
    char sourceFileName[100], destinationFileName[100];
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    printf("Enter the name of the source file: ");
    scanf("%s", sourceFileName);


    sourceFile = fopen(sourceFileName, "rb");
    if (sourceFile == NULL) {
        printf("Failed to open the source file.\n");
        return 1;
    }

    printf("Enter the name of the destination file: ");
    scanf("%s", destinationFileName);

   
    destinationFile = fopen(destinationFileName, "wb");
    if (destinationFile == NULL) {
        printf("Failed to create the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

 
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destinationFile);
    }


    fclose(sourceFile);
    fclose(destinationFile);

    printf("File copied successfully.\n");

    return 0;
}

