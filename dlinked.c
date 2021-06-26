#include<stdio.h>
#include<stdlib.h>
struct node{
			int info;
			struct node *next;
			};
typedef struct node node1;

void initlist(node1 **list)
{
	*list=NULL;
	
}
void enterlist(node1 **list,int x)
{
	node1 *l,*back,*q;
	l=(node1*)(malloc(sizeof(node1)));
	l->info=x;
	if (*list==NULL || x<(*list)->info)
	{
		l->next=*list;
		*list=l;
	}
	else
	{
		back=*list;
		q=*list;
		while(q!=NULL && q->info<x)
		{
			back=q;
			q=q->next;
		}
		back->next=l;
		l->next=q;
	}
}
void deletelist(node1 **list,int x)
{
	node1 *l,*back;
	l=*list;
	while (l!=NULL && l->info<x)
	{
		back=l;
		l=l->next;
	}
	if (l!=NULL && l->info==x)
	{
		if (l==*list)
		{
			*list=l->next;
		}
		else
		{
			back->next=l->next;
		}
		free(l);
	}
	else
	printf("value not present in the list\n");
}
int searchlist(node1 *list,int x)
{
	while(list!=NULL && list->info<x)
	list=list->next;
	if (list->info==x)
	return 1;
	else
	return 0;
}
void traverselist(node1 *list)
{
	while(list!=NULL)
	{
		printf("%d--> ",list->info);
		list=list->next;
	}
	printf("\n");
}
int emptylist(node1 *list)
{
	if (list==NULL)
	return 1;
	else 
    return 0;
}
int main()
{
	node1 *list;
	int choice,v,i;
	initlist(&list);
	do{
		printf("1. Enter a value in list\n");
		printf("2. Delete a value from list\n");
		printf("3. Search in list\n");
		printf("4. Traverse the list\n");
		printf("5. EXIT\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
				printf("Give value to enter: ");
				scanf("%d",&v);
				enterlist(&list,v);
				break;
		case 2:
				printf("Give value to delete: ");
				scanf("%d",&v);
				if (emptylist(list)==0)
				deletelist(&list,v);
				else
				printf("list empty, cannot delete\n");
				break;
		case 3:
				printf("Give value to search: ");
				scanf("%d",&v);
				if (searchlist(list,v)==1)
				printf("Value found in list\n");
				else
				printf("value not found in list\n");
				break;
		case 4:
				printf("The List-->");
				traverselist(list);
				printf("\n");
				break;
		case 5:
				printf("Thank you, BYE\n");
				break;
		default:
				printf("invalid choice, enter again\n");
		}
	} while(choice!=5);	
}
