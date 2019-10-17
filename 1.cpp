#include<stdio.h>
#include<stdlib.h>

struct node
{
int info;
struct node*next;	
}*start=NULL;

int add_end(int d)
{
	struct node*newcode,*temp;
	newcode=(struct node*)malloc(sizeof(struct node));
	newcode->info=d;
	newcode->next=NULL;
	temp=start;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newcode;
}

int add_beg(int a)
{
struct node*newcode;
	newcode=(struct node*)malloc(sizeof(struct node));
	newcode->info=a;
	newcode->next=start;
	start=newcode;
}

int del_beg()
{
	struct node*newcode,*temp;
	temp=start;
	start=start->next;
	free(temp);
}

int del_end()
{
	struct node*temp,*ptr;
	temp=start;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	ptr=temp->next;
	temp->next=NULL;
	free(ptr);
}

void display()
{
	struct node*temp;
	temp=start;
	printf("{");
	while(temp!=NULL)
	{
		printf("%d,",temp->info);
		temp=temp->next;
	}
	printf("}\n");
}

int main()
{ 
    int n;
	printf("Choose any  function inorder to proceed further \n");
	while(1)
	{
	printf("\n1. To add a number in the beginning \n");
	printf("2. To add a number in the end \n");
	printf("3. To delete the first number \n");
	printf("4. To delete the last number \n");
	printf("5. Display \n");
	scanf("%d",&n);
	
	switch(n)
	{
		case 1: add_beg(14);
		        printf("Required result : %d ",add_beg(14));
		
		break;
		
		case 2: add_end(12);
		        printf("Required result : %d ",add_end(12));
		break;
		
		case 3: del_beg();
		        printf("Required result : %d ",del_beg());
		break;
		
		case 4: del_end();
		        printf("Required result : %d ",del_end());
		break;
		
		case 5: printf("\n Nodes are: ");
		        display();
		        printf("\n");
		break;
		
		default : printf("Invalid Choice ");
	}
	
	}
	return 0;
}
