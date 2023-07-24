#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int computeTotalSeconds(const char str[]) {
    int hours = 0, minutes = 0, seconds = 0;

    sscanf(str, "%d:%d:%d", &hours, &minutes, &seconds);

    int totalSeconds = hours * 3600 + minutes * 60 + seconds;

    return totalSeconds;
}

int main() {
    char str[100];
    printf("Enter a time duration in HH:MM:SS format: ");
    scanf("%s", str);

    int totalSeconds = computeTotalSeconds(str);

    printf("Total seconds: %d\n", totalSeconds);

    return 0;
}

