#include <stdio.h>
#include <stdlib.h>

struct node
{
	int pid; //Process ID
	int at;  //Arrival Time
	int bt;  //Burst Time
	struct node *next;
} *head = NULL, *next = NULL;

void fcfs()
{
	int r=0;
	struct node *tem = malloc(sizeof(struct node));
	tem = head;
	if (tem == NULL)
		printf("No Processes\n");
	else
	{
		while (tem->next != NULL)
		{
			if (tem->at > (tem->next)->at)
			{
				r = tem->pid;
				tem->pid = (tem->next)->pid;
				(tem->next)->pid = r;
				r = tem->at;
				tem->at = (tem->next)->at;
				(tem->next)->at = r;
				r = tem->bt;
				tem->bt = (tem->next)->bt;
				(tem->next)->bt = r;
				tem = tem->next;
			}
			else
			{
				tem = tem->next;
			}
		}
		tem = head;
		while (tem != NULL)
		{
			if(tem->next == NULL)
				printf("%d", tem->pid);
			else
				printf("%d->", tem->pid);
			tem = tem->next;
		}
		printf("\n");
		printf("\n");
	}
}

void sjf()
{
	int r=0;
	struct node *tem = malloc(sizeof(struct node));
	tem = head;
	if (tem == NULL)
		printf("No Processes\n");
	else
	{
		while (tem->next != NULL)
		{
			if (tem->at > (tem->next)->at)
			{
				r = tem->pid;
				tem->pid = (tem->next)->pid;
				(tem->next)->pid = r;
				r = tem->at;
				tem->at = (tem->next)->at;
				(tem->next)->at = r;
				r = tem->bt;
				tem->bt = (tem->next)->bt;
				(tem->next)->bt = r;
				
				tem = tem->next;
			}
			
			else
			{
				tem = tem->next;
			}
		}
		
		tem = head;
		tem = tem->next;
		
		while(tem->next!=NULL)
		{
			if(tem->bt > (tem->next)->bt)
			{
				r = tem->pid;
				tem->pid = (tem->next)->pid;
				(tem->next)->pid = r;
				r = tem->at;
				tem->at = (tem->next)->at;
				(tem->next)->at = r;
				r = tem->bt;
				tem->bt = (tem->next)->bt;
				(tem->next)->bt = r;
				
				tem = tem->next;
			}
			
			else
			{
				tem = tem->next;
			}
		}
		tem = head;
		while (tem != NULL)
		{
			if(tem->next == NULL)
				printf("%d", tem->pid);
			else
				printf("%d->", tem->pid);
			tem = tem->next;
		}
		printf("\n");
		printf("\n");
	}
}

int main()
{
	unsigned int n, i, ch;
	printf("How many processes would you like to schedule?\n");
	scanf("%u", &n);
	for (i = 0; i < n; i++)
	{
		struct node *nn = malloc(sizeof(struct node));
		struct node *temp = malloc(sizeof(struct node));
		if (head == NULL)
		{
			printf("Enter the process id: \n");
			scanf("%d", &nn->pid);
			printf("Enter the arrival time: \n");
			scanf("%d", &nn->at);
			printf("Enter the burst time: \n");
			scanf("%d", &nn->bt);
			head = nn;
		}
		else
		{
			temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			printf("Enter the process id: \n");
			scanf("%d", &nn->pid);
			printf("Enter the arrival time: \n");
			scanf("%d", &nn->at);
			printf("Enter the burst time: \n");
			scanf("%d", &nn->bt);
			temp->next = nn;
		}
	}
	printf("Process   Arrival time   Burst time\n");
	struct node *t = malloc(sizeof(struct node));
	t = head;
	for (int i = 0; i < n; i++)
	{
		while (t != NULL)
		{
			printf("   %d ", t->pid);
			printf("         %d ", t->at);
			printf("       	    %d", t->bt);
			printf("\n");
			t = t->next;
		}
	}

	printf("Please enter your choice: \n");
	printf("1)FCFS\n");
	printf("2)SJF\n");
	printf("3)Round Robbin\n");
	printf("4)Exit\n");
	scanf("%u", &ch);
	printf("\n");

	while (ch!=4)
	{
		switch (ch)
		{
			case 1:
				printf("You Have Picked FCFS\n");
				fcfs();
				printf("\n");
				break;
			case 2:
				printf("You Have Picked SJF\n");
				sjf();
				printf("\n");
				break;
			case 3:
				printf("You have Picked Round Robbin\n");
				//rr();
				printf("\n");
				break;
			default:
				printf("Incorrect Choice.\n");
		}

		printf("Please enter your choice: \n");
		printf("1)FCFS\n");
		printf("2)SJF\n");
		printf("3)Round Robbin\n");
		printf("4)Exit\n");
		scanf("%u", &ch);
		printf("\n");
	}
	return 0;
}
