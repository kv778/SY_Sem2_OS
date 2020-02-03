#include<stdio.h>
#include <unistd.h> 
 
int main() 
{ 
	int a[] = {2,4,1,3,9,6,8,5,10,7}; 
	int n = 10; 
	int id = fork(); 

	// Checking value of process id returned by fork 
	if (id > 0)
	{	 	
		int temp=0;
		printf("Parent Process \n"); 
		
		//Sorting in ascending order
		for(int i=0;i<n-1;i++)
		{
			for(int j=0;j<n-i-1;j++)
			{
				if(a[j]>a[j+1])
				{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		} 
 
		printf("Sorted Array : "); 
		for (int i=0;i<n;i++)
			printf("%d \t",a[i]);  
		
		printf("\n"); 
	} 

	// If n is 0, we are in child process 
	else
	{
		int temp=0; 
		printf("Child Process \n"); 
		
		//Sorting in descending order
		for(int i=0;i<n-1;i++)
		{
			for(int j=0;j<n-i-1;j++)
			{
				if(a[j]<a[j+1])
				{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		} 
 
		printf("Sorted Array : "); 
		for (int i=0;i<n;i++)
			printf("%d \t",a[i]);  
		
		printf("\n");	 
	} 

	return 0; 
} 

