//*********************************************************
//
// Sumedh Saurabh
// Operating Systems
// Project #1: New Island Shell - Writing Your Own Shell
//
//*********************************************************


//*********************************************************
//
// Includes and Defines
//
//*********************************************************
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <wait.h>

#define STDIN 0
#define STDOUT 1


using namespace std;

//*********************************************************
//
// Extern Declarations
//
//*********************************************************
using namespace std;
extern "C"
{
  extern char **gettoks();
} 


//*********************************************************
//
// Main Function
//
//*********************************************************
int main( int argc, char *argv[] )
{
  // local variables
  int ii;
  char **toks;
  int retval;

  pid_t pid;
  int status;
  int BUFFER_SIZE = 4096;
  char folder[80];
  retval = 0;
  // show shell prompt
  printf("%c", '%');
  // get coomand and arguments
  toks = gettoks();

  if( toks[0] != NULL )
  {
     pid = fork();
     if(pid == 0)     // In child process 
     {

        strcpy(folder,"/bin/");
        strcat(folder,toks[0]);
   
        execv(folder, toks);
      }
      else            // In prent process
      {
        wait(&status);
     }
  }
  return( retval );
}

