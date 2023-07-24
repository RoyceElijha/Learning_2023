#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LINE_LENGTH 100

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char time[9];
} LogEntry;

void extractLogEntries(FILE *file, LogEntry logEntries[], int *numEntries) {
    char line[MAX_LINE_LENGTH];
    char *token;
    int entryCount = 0;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        token = strtok(line, ",");
        logEntries[entryCount].entryNo = atoi(token);

        token = strtok(NULL, ",");
        strcpy(logEntries[entryCount].sensorNo, token);

        token = strtok(NULL, ",");
        logEntries[entryCount].temperature = atof(token);

        token = strtok(NULL, ",");
        logEntries[entryCount].humidity = atoi(token);

        token = strtok(NULL, ",");
        logEntries[entryCount].light = atoi(token);

        token = strtok(NULL, ",");
        strcpy(logEntries[entryCount].time, token);

        entryCount++;
    }

    *numEntries = entryCount;
}

void displayLogEntries(LogEntry logEntries[], int numEntries) {
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTime\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%d\t%s\t\t%.1f\t\t%d\t\t%d\t%s\n",
               logEntries[i].entryNo, logEntries[i].sensorNo, logEntries[i].temperature,
               logEntries[i].humidity, logEntries[i].light, logEntries[i].time);
    }
}

int main() {
    LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;

    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    extractLogEntries(file, logEntries, &numEntries);
    fclose(file);

    displayLogEntries(logEntries, numEntries);

    return 0;
}

