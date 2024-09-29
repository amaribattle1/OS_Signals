#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>


// Global variables to track the number of alarms and start time
volatile sig_atomic_t alarmCount = 0;
time_t startTime;

void alarmHandler(int signum)
{ //signal handler for SIGALRM
  printf("Hello World!\n");
  alarmCount++; // Increment the alarm count
  alarm(1);     // Schedule the next alarm for 1 second
}

void intHandler(int signum)
{ //signal handler for SIGINT (CTRL-C)
  time_t endTime = time(NULL); // Get the current time when interrupted
  printf("\nTuring was right!\n");
  printf("Total alarms: %d\n", alarmCount);
  printf("Total execution time: %ld seconds\n", endTime - startTime);
  exit(0); // Exit the program
}

int main(int argc, char *argv[])
{
  signal(SIGALRM, alarmHandler); // register handler to handle SIGALRM
  signal(SIGINT, intHandler);    // register handler to handle SIGINT (CTRL-C)
  
  startTime = time(NULL); // Record the start time
  alarm(1);               // Schedule the first alarm for 1 second
  
  // Infinite loop to keep the program running and responding to signals
  while (1);

  return 0;
}

