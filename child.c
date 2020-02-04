#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LSIZ 128 
#define RSIZ 10
#define A 500
#define B 600 
#define C 700
    
int main (int argc, char **argv)
{   
 int i, j,temp,n,num[15];
long sum;
FILE *file = fopen("contacts.txt", "r");
int integers[100];
int k;
while(fscanf(file, "%d", &k) > 0) {
integers[i] = num;
i++;
 }
fclose(file);
printf ("Child: Hello, \n");

printf("Child process exucuting\n");
for(i = 0 ; i < n ; i++ )
{
for(j = 0 ; j < n-i-1 ; j++)
{
if(num[j] > num[j+1])
{
temp = num[j];
num[j] = num[j+1];
 num[j+1] = temp;
 }
 }
                }
                printf("The sorted array is:\n");
                for(i = 0 ; i < n ; i++)
                {
                 printf("%d ",num[i]);
                }
                printf("\n");
    printf ("Child: Work completed!\n");
    printf ("Child: Bye now.\n");

    exit (0);
}

