// parent.c: the parent program

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main (int argc, char **argv)
{
    int i = 0;
    long sum;
    int pid;
    int status, ret;
    char *myargs [] = { NULL };
    char *myenv [] = { NULL };

    printf ("Parent: Hello, World!\n");
     int num;
   FILE *fptr;
  	fptr = fopen("contacts.txt","w");
   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
   for(i=0;i<5;i++)
   {
   printf("Enter num: ");
   scanf("%d",&num);
   fprintf(fptr,"%d",num);
   fprintf(fptr, "\n");
   }
   fclose(fptr);
  

    pid = fork ();

    if (pid == 0) {

        // I am the child

        execve ("child", myargs, myenv);
    }
    

    // I am the parent

    printf ("Parent: Waiting for Child to complete.\n");

    if ((ret = waitpid (pid, &status, 0)) == -1)
         printf ("parent:error\n");

    if (ret == pid)
        printf ("Parent: Child process waited for.\n");
}
