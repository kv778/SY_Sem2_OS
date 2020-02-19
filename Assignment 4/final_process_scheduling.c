#include <stdio.h>
#include <stdlib.h>

struct node
{
	int pid; //Process ID
	int at;  //Arrival Time
	int bt;  //Burst Time
	int wt, tt, rt;
	char name;
	int completed;
	float ntt;
	struct node *next;
} p[10], *head = NULL, *next = NULL;

void fcfs()
{
	int r = 0;
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
			if (tem->next == NULL)
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
	int r = 0;
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

		while (tem->next != NULL)
		{
			if (tem->bt > (tem->next)->bt)
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
			if (tem->next == NULL)
				printf("%d", tem->pid);
			else
				printf("%d->", tem->pid);
			tem = tem->next;
		}
		printf("\n");
		printf("\n");
	}
}

int n;
float avgtt;
int q[10];
int front = -1, rear = -1;
void enqueue(int i)
{
	if (rear == 10)
		printf("overflow");
	rear++;
	q[rear] = i;
	if (front == -1)
		front = 0;
}

int dequeue()
{
	if (front == -1)
		printf("underflow");
	int temp = q[front];
	if (front == rear)
		front = rear = -1;
	else
		front++;
	return temp;
}
int isInQueue(int i)
{
	int k;
	for (k = front; k <= rear; k++)
	{
		if (q[k] == i)
			return 1;
	}
	return 0;
}
void sortByArrival()
{
	struct node temp;
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
		{
			if (p[i].at > p[j].at)
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
}

/*In this function for implementing process scheduling by using the Round Robin method, I've had to 
take the input, i.e. the processes and their arrival and burst times since I've used a completely new
data structure, namely queues, instead of linked lists as used for FCFS and SJF*/

void rr()
{
	int i, j, time = 0, sum_bt = 0, tq;
	char c;
	float avgwt = 0;
	printf("Enter no of processes:");
	scanf("%d", &n);
	for (i = 0, c = 'A'; i < n; i++, c++)
	{
		p[i].name = c;
		printf("\nEnter the arrival time and burst time of process %c: ", p[i].name);
		scanf("%d%d", &p[i].at, &p[i].bt);
		p[i].rt = p[i].bt;
		p[i].completed = 0;
		sum_bt += p[i].bt;
	}

	printf("\nEnter the time quantum:");
	scanf("%d", &tq);

	sortByArrival();
	enqueue(0);
	printf("\nProcess execution order: ");
	for (time = p[0].at; time < sum_bt;)
	{
		i = dequeue();

		if (p[i].rt <= tq)
		{

			time += p[i].rt;
			p[i].rt = 0;
			p[i].completed = 1;
			printf(" %c ", p[i].name);
			p[i].wt = time - p[i].at - p[i].bt;
			p[i].tt = time - p[i].at;
			p[i].ntt = ((float)p[i].tt / p[i].bt);
			for (j = 0; j < n; j++)
			{
				if (p[j].at <= time && p[j].completed != 1 && isInQueue(j) != 1)
				{
					enqueue(j);
				}
			}
		}
		else
		{
			time += tq;
			p[i].rt -= tq;
			printf(" %c ", p[i].name);
			for (j = 0; j < n; j++)
			{
				if (p[j].at <= time && p[j].completed != 1 && i != j && isInQueue(j) != 1)
				{
					enqueue(j);
				}
			}
			enqueue(i);
		}
	}
	printf("\n");
	printf("\nName\tArrival Time\tBurst Time\tWaiting Time\tTurnAround Time\t Normalized TT");
	for (i = 0; i < n; i++)
	{
		avgwt += p[i].wt;
		printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d\t\t%f", p[i].name, p[i].at, p[i].bt, p[i].wt, p[i].tt, p[i].ntt);
	}
	printf("\n");
	printf("\nAverage waiting time:%f\n", avgwt / n);
	printf("\nAverage Turnaround Time: %f\n", avgtt / n);
	printf("\n");
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
	printf("1)First Come First Serve (FCFS)\n");
	printf("2)Shortest Job First (SJF)\n");
	printf("3)Round Robbin\n");
	printf("4)Exit\n");
	scanf("%u", &ch);
	printf("\n");

	while (ch != 4)
	{
		switch (ch)
		{
		case 1:
			printf("You Have Picked First Come First Serve (FCFS)\n");
			fcfs();
			printf("\n");
			break;
		case 2:
			printf("You Have Picked Shortest Job First (SJF)\n");
			sjf();
			printf("\n");
			break;
		case 3:
			printf("You have Picked Round Robbin\n");
			rr();
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
