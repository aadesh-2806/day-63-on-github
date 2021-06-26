#include<stdio.h>
#include<stdlib.h>
struct node{
			int info;
			struct node *left,*right;
			};
typedef struct node node1;

void initbst(node1 **root)
{
	*root=NULL;
}
void enterbst(node1 **root,int x)
{
	node1 *p,*q,*back;
	p=(node1*)(malloc(sizeof(node1)));
	p->info=x;
	p->left=NULL;
	p->right=NULL;
	if (*root==NULL)
	*root=p;
	else
	{
		q=*root;
		back=*root;
		while (q!=NULL)
		{
			back=q;
			if (x<q->info)
			q=q->left;
			else
			q=q->right;
		}
		if (x<back->info)
		back->left=p;
		else
		back->right=p;
	}
}
void deletebst(node1 **list,int x)
{
	printf("WILL BE IMPLEMENTED LATER\n");
}
int searchbst(node1 *root,int x)
{
	printf("WILL BE IMPLEMENTED LATER\n");
}
void inorder(node1 *root)
{
	if (root!=NULL)
	{
		inorder(root->left);
		printf("%d  ",root->info);
		inorder(root->right);
	}
}
void preorder(node1 *root)
{
	if (root!=NULL)
	{
		printf("%d  ",root->info);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(node1 *root)
{
	if (root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d  ",root->info);
	}
}
int emptybst(node1 *root)
{
	if (root==NULL)
	return 1;
	else 
    return 0;
}
int main()
{
	node1 *root;
	int choice,v,i;
	initbst(&root);
	do{
		printf("1. Enter a value in bst\n");
		printf("2. Delete a value from bst\n");
		printf("3. Search in bst\n");
		printf("4. In-order traversal\n");
		printf("5. Pre-order taversal\n");
		printf("6. Post-order traversal\n");
		printf("7. EXIT\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
				printf("Give value to enter: ");
				scanf("%d",&v);
				enterbst(&root,v);
				break;
		case 2:
				printf("Give value to delete: ");
				scanf("%d",&v);
				if (emptybst(root)==0)
				deletebst(&root,v);
				else
				printf("bst empty, cannot delete\n");
				break;
		case 3:
				printf("Give value to search: ");
				scanf("%d",&v);
				if (searchbst(root,v)==1)
				printf("Value found in bst\n");
				else
				printf("value not found in bst\n");
				break;
		case 4:
				printf("The INORDER traversal is:\n");
				inorder(root);
				printf("\n");
				break;
		case 5:
				printf("The PREORDER traversal is:\n");
				preorder(root);
				printf("\n");
				break;
		case 6:
				printf("The POSTORDER traversal is:\n");
				postorder(root);
				printf("\n");
				break;
		case 7:
				printf("Thank you, BYE\n");
				break;
		default:
				printf("invalid choice, enter again\n");
		}
	} while(choice!=7);	
}
