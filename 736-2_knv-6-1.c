#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	int key;
	struct node *left;
	struct node *right;
	} node;

typedef node *tree;

typedef struct snode {
	tree actual;
	struct snode* prev;
	} snode;

typedef snode *stack;

int init(tree* root)
{
	*root = NULL;
	return 1;
}

int initstack(stack* top)
{
	*top = NULL;
//	(*top) -> actual = NULL;
	return 1;
}

int isEmpty(stack top)
{
	if (top == NULL) return 1;
	else return 0;
}

int push(stack *top, tree root )
{
	stack tmp = (stack) malloc(sizeof(snode));
	(tmp -> actual) = root;
	(tmp -> prev) = (*top);
	(*top) = tmp;
	return 1;
}

tree pop( stack *top )
{
	stack tmp = (*top);
	tree actual = tmp -> actual;
	(*top) = (*top) -> prev;
	free( tmp );
	return actual;
}

int add(tree* root, int key, int data)
{
	tree tmp = malloc(sizeof(node));
	tmp -> data = data;
        tmp -> key = key;
        tmp -> left = NULL;
        tmp -> right = NULL;
	if ((*root) == NULL)
	{
		*root = tmp;
		return 1;
	}
	while ( 1 )
	{
		if ((*root) -> key < key)
		{
			if ((*root) -> right == NULL)
			{
				(*root) -> right = tmp;
				return 1;
				
			}
			root=&((*root) -> right);
			
		}
		else if ((*root) -> key > key)
		{
			if ((*root) -> left == NULL)
                        {
				(*root) -> left = tmp;
				return 1;

                        }
			root=&((*root) -> left);
		}
		else return 1;
	}
}

int postOrder(tree *lst)
{
	
	if (*lst == NULL ) return 1;
	postOrder(&((*lst)->left));
	postOrder(&((*lst) -> right));
	printf("%d ",(*lst) -> data);
}

int postOrder2(tree lst)
{
	stack w;
	tree tmp = lst;
	initstack(&w);
	while ( tmp != NULL || isEmpty(w) != 1 )
	{
             	if ( isEmpty(w) != 1 )
		{
                	tmp = pop(&w);
			if ( tmp -> right != NULL)
			{
				tree a = tmp;
				push(&w, a);
				tmp = (tmp -> right);
				a -> right = NULL;
			}
			else
			{
				printf("%d ", tmp -> data);
				tmp = NULL;
             		}
		}
        	while( tmp != NULL )
		{
			push(&w,tmp);
			tmp = (tmp -> left);
        	}
        }
	return 1;
}

int main()
{
	tree m;
	init(&m);
	int i,n, val, k, a, b, c;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d %d", &k, &val);
		add(&m, k, val);
	}
//	postOrder(&m);
//	printf("\n");
	postOrder2(m);
        printf("\n");
	return 0;
}
