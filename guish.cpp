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
#include <sstream>
#include <wait.h>
#include <vector>

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

  ii=0;
  pid_t pid;
  int status;
  int BUFFER_SIZE = 4096;
  char folder[80];
  retval = 0;
  stringstream buffer;
  string temp = "";
  vector<string> prevCMD;


  while(true){ 
     // get coomand and arguments
     toks = gettoks();


     // show shell prompt
     printf("%c", '%');
     if( toks[0] != NULL )
     {
     	  pid = fork();
     	  if(pid == 0)     // In child process 
     	  {

 		for( ii=0; toks[ii] != NULL; ii++ ){
			
			temp = toks[ii];			
			prevCMD.push_back(temp);
			temp = "";
						
       		 	strcpy(folder,"/bin/");
        		strcat(folder,toks[0]);
   
        		execv(folder, toks);
                	

			cout << "Argument " << ii << ": " << toks[ii] << endl;
			
		
		}
    	   }
     	   else            // In prent process
      	   {
       	       	wait(&status);
           }

       	if( !strcmp( toks[0], "exit" )){		
			break;
	}else if( !strcmp( toks[0], "hist" )){
	 	for(int i = 0; i < prevCMD.size(); i++){
			cout << prevCMD[i] << endl;
		}	
	}else if( !strcmp( toks[0], "pwd" )){
		
	}
      }
  }
  return( retval );
}

