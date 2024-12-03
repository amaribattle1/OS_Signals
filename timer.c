
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

// Global variables to track alarm counts and start time
int alarm_count = 0;
time_t start_time;

// Signal handler for SIGALRM
void handler(int signum) {
    alarm_count++;  // Increment alarm count
    alarm(1);  // Set the next alarm for 1 second
}

// Signal handler for SIGINT (Ctrl-C)
void sigint_handler(int signum) {
    time_t end_time = time(NULL);  // Get current time
    double elapsed_time = difftime(end_time, start_time);
    
    printf("\nProgram executed for %.0f seconds.\n", elapsed_time);
    printf("Total alarms delivered: %d\n", alarm_count);
    exit(0);  // Exit the program
}

// Main function
int main() {
    // Set up signal handlers
    signal(SIGALRM, handler);
    signal(SIGINT, sigint_handler);

    // Record start time
    start_time = time(NULL);

    // Start the first alarm
    alarm(1);

    // Wait indefinitely for signals
    while (1) {
        pause();  // Wait for signals
    }

    return 0;
}
