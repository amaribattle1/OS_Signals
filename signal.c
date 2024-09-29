/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t turingFlag = 0;
void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  turingFlag = 1; 
  
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(5); //Schedule a SIGALRM for 5 seconds
  while (1){
    if (turingFlag){
      printf("Turing was right!\n");
      turingFlag = 0; // Reset the flag
      alarm(5);       // Schedule next alarm
    }
  }

  return 0;
}