#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *left,*right;
}*root;
void create_tree();
void main()
{
	int choice;
	root=(struct node*)malloc(sizeof(struct node));
	root->left=NULL;
	root->right=NULL;

	clrscr();
	while(1)
	{
		print("\npress(1)for creating a tree\npress(10)to exit\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			create_tree();
		}
		else if(choice==10)
		{
			break;
		}
	}
	getch();
}
void create_tree()
{
	int num=0,value,i;
	struct node *temp;
	if(root==NULL)
	{
		print("\nunable to allocate memory\n");
		return;
	}
	print("\nenter number of nodes:");
	scanf("%d",&num);

	if(num>0)
	{
		print("\nenter value: ");
		scanf("%d",&value);
		root->data=value;
	}
	temp=root;

	for(i=1;i<num;i++)
	{
		struct node *newnode;
		newnode=(struct node*)malloc(sizeof(struct node));
		temp=root;
		if(newnode==NULL)
		{
			print("\nunable to allocate memory\n");
			return;
		}
		print("\nenter value: ");
		scanf("%d",&value);
		newnode->data=value;
		newnode->left=NULL;
		newnode->right=NULL;
		while(1)
		{
			if((temp->data)<(newnode->data))
			{
				if(temp->left==NULL)
				{
					temp->left=newnode;
					break;
				}
				else
				{
					temp=temp->left;
					continue;
				}
			}
			if((temp->data)>(newnode->data))
			{
				if(temp->right==NULL)
				{
					temp->right=newnode;
					break;
				}
				else
				{
					temp=temp->right;
					continue;
				}
			}
		}


	}

}