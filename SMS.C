#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int enroll_no;
	char name[10];
	int per;
	struct node *next;
}*head,*temphead;

void create_linklist();
char *upper_to_lower(char []);
void printlinklist();
void insert_begning();
void search();
void delete_node();
void shorting();
void main()
{
	int n,choice;
	clrscr();
	head = (struct node *)malloc(sizeof(struct node));
	head->next=NULL;
	while(1)
	{
		printf("______________________");
		printf("\n|1| create linklist  |\n|2| insert data   |\n|3| print data   |\n|4| search data    |\n|5| delete data     |\n|6| shorting               |\n|7| exit|\n");
		printf("______________________\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			create_linklist();
		}
		else if(choice==2)
		{
			insert_begning();
		}
		else if(choice==3)
		{
			printlinklist();
		}
		else if(choice==4)
		{
			search();
		}
		else if(choice==5)
		{
			delete_node();
		}
		else if(choice==6)
		{
			shorting();
		}
		else if(choice==7)
		{
			break;
		}
		else
		{
			printf("\ninvalid choice\n");
		}
	}
	getch();
}
void create_linklist()
{
	int n,enroll_no,per,i;
	char name[10],*na;
	struct node *newnode, *temp;

	printf("Enter the total number of nodes: ");
	scanf("%d", &n);


	if(head == NULL)
	{
		printf("Unable to allocate memory.");
		exit(0);
	}
	printf("Enter enroll_no: ");
	scanf("%d", &enroll_no);
	printf("Enter name: ");
	gets(name);
	gets(name);
	na=upper_to_lower(name);
	printf("Enter percentage: ");
	scanf("%d", &per);

	head->enroll_no =enroll_no;
	strcpy(head->name,na);
	head->per =per;
	head->next = NULL;
	temp = head;
	for(i=2; i<=n; i++)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		if(newnode == NULL)
		{
			printf("Unable to allocate memory.");
			break;
		}
		printf("Enter enroll_no: ");
		scanf("%d", &enroll_no);
		printf("Enter name: ");
		gets(name);
		gets(name);
		na=upper_to_lower(name);
		printf("Enter percentage: ");
		scanf("%d", &per);

		newnode->enroll_no =enroll_no;
		strcpy(newnode->name,na);
		newnode->per =per;
		newnode->next = NULL;

		temp->next = newnode;
		temp = temp->next;
	}
}
void insert_begning()
{
	struct node *newnode,*temp;
	int enroll_no,per;
	char name[10],*n;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter enroll_no: ");
	scanf("%d", &enroll_no);
	printf("Enter name: ");
	gets(name);
	gets(name);
	n=upper_to_lower(name);
	printf("Enter percentage: ");
	scanf("%d", &per);
	newnode->enroll_no =enroll_no;
	strcpy(newnode->name,n);
	newnode->per =per;
	newnode->next = NULL;
	temp=head;
	head=newnode;
	newnode->next=temp;
}
void printlinklist()
{
	struct node *temp;
	if(head == NULL)
	{
		printf("List is empty");
		return;
	}
	temp = head;
	while(temp != NULL)
	{
		printf("enroll_no= %d\n", temp->enroll_no);
		printf("name= ");
		puts(temp-> name);
		printf("\n");
		printf("percentage= %d\n", temp->per);
		temp = temp->next;
	}
}

void search()
{
	struct node *temp;
	int value;
	temp = head;
	printf("enter enroll_no to be searched: ");
	scanf("%d",&value);
	while(temp->next!= NULL)
	{
		if(temp->enroll_no==value)
		{
			printf("\nfound\n");
			return;
		}
		temp = temp->next;
	}
	if(temp->enroll_no==value)
	{
		printf("\nfound\n");
		return;
	}
	else
	{
		printf("\nnot found\n");
		return;
	}
}
void delete_node()
{
	struct node *temp,*temp2;
	int value;
	temp = head;
	temp2=temp;
	printf("enter enroll_no to be deleted: ");
	scanf("%d",&value);
	if(temp->enroll_no==value)
	{
		head=temp->next;
		return;
	}
	while(temp->next!= NULL)
	{

		if(temp->enroll_no==value)
		{
			temp2->next=temp->next;
			return;
		}
		temp2=temp;
		temp = temp->next;
	}
	if(temp->enroll_no==value)
	{
		temp2->next=NULL;
		return;
	}
	else
	{
		printf("\nnot found\n");
		return;
	}

}
char * upper_to_lower(char str[])
{
	int i;
	for ( i = 0; i <= strlen (str); i++)
	{
// The ASCII value of A is 65 and Z is 90
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32; /* add 32 to string character to convert into lower case. */
	}
	return str;
}

void shorting()
{
	int i,j,count=0,temp_enroll,temp_per;
	char temp_name[10];
	struct node *pre1,*pre2,*cur1,*cur2,*temp;
	temp=head;
	while(temp!= NULL)
	{
		count++;
		temp = temp->next;
	}
	cur1=head;
	cur2=head->next;
	for(i=0;i<count;i++)
	{
		for(j=i+1;j<count;j++)
		{
			if((cur1->per)< (cur2->per))
			{
				temp_enroll=cur1->enroll_no;
				temp_per=cur1->per;
				strcpy(temp_name,cur1->name);
				cur1->enroll_no=cur2->enroll_no;
				cur1->per=cur2->per;
				strcpy(cur1->name,cur2->name);
				cur2->enroll_no=temp_enroll;
				cur2->per=temp_per;
				strcpy(cur2->name,temp_name);
			}
			cur2=cur2->next;
		}
		cur1=cur1->next;
		cur2=cur1->next;
	}
}