#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[],char *en[])
{
    int i,j,c,ele;
    int arr[argc];
int size=0;
    for (j = 0; j < argc-1; j++)
    {
        int n=atoi(argv[j]);
        arr[j]=n;
size++;
    }
    ele=atoi(argv[j]);
    i=0;
    j=argc-1;   
    c=(i+j)/2;
    while(arr[c]!=ele && i<=j)
    {
        if(ele > arr[c])
            i = c+1;
        else
            j = c-1;

        c = (i+j)/2;
    }
    if(i<=j)
{
        printf("\nElement Found in the given Array...!!!\n");
	printf("\nPrinting In Reverse Order Now :");
 	for(i=size-1;i>=0;i--)
	{
	printf("\t%d",arr[i]);
	}
	printf("\n");
}
    else 
{  
        printf("\nElement Not Found in the given Array...!!!\n");
	printf("\nPrinting In Reverse Order Now :");
	for(i=size-1;i>=0;i--)
	{
	printf("\t%d",arr[i]);
	}
	printf("\n");
}
} 
