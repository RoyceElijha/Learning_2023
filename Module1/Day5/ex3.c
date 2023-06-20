#include <stdio.h>

// Structure definition for a time period
struct Time {
    int hours;
    int minutes;
    int seconds;
};

// Function to calculate the difference between two time periods
struct Time calculateTimeDifference(struct Time t1, struct Time t2) {
    struct Time diff;

    int totalSeconds1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int totalSeconds2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
    int diffSeconds = totalSeconds2 - totalSeconds1;

    // Calculate hours, minutes, and seconds from the difference in seconds
    diff.hours = diffSeconds / 3600;
    diffSeconds %= 3600;
    diff.minutes = diffSeconds / 60;
    diff.seconds = diffSeconds % 60;

    return diff;
}

int main() {
    struct Time time1, time2;

    // Prompt the user to enter the first time period
    printf("Enter the first time period (hours minutes seconds): ");
    scanf("%d %d %d", &(time1.hours), &(time1.minutes), &(time1.seconds));

    // Prompt the user to enter the second time period
    printf("Enter the second time period (hours minutes seconds): ");
    scanf("%d %d %d", &(time2.hours), &(time2.minutes), &(time2.seconds));

    // Calculate the difference between the time periods
    struct Time diff = calculateTimeDifference(time1, time2);

    // Print the difference between the time periods
    printf("Time Difference: %d hours %d minutes %d seconds\n", diff.hours, diff.minutes, diff.seconds);

    return 0;
}

