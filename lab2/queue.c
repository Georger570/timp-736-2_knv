#include <stdio.h>
#include <stdlib.h>


typedef struct node {
        int data;
        struct node *prev;
        struct node *next;
} node;

typedef node* queue;
typedef enum {false, true} bool;

queue top=NULL;
queue back=NULL;


int init(queue* root)
{
        *root = NULL;
        return 1;
}


int destroy(queue* root)
{
        queue x, t;
        x=*root;
        t=*root;
        while ( x != NULL )
        {
                t = x ->next;
                free (x);
                x = t;
        }
        *root  = NULL;
        return 1;
}
bool isEmpty(queue root)
{
        if (root == NULL)
        {
                return true;
        }
        else
        {
                return false;
        }
}


int push(queue* lst, int data)
{

        queue tmp = malloc(sizeof(node));
        tmp -> prev = NULL;
        tmp -> next = (*lst);
        (*lst) -> prev = tmp;
        tmp -> data = data;
        (*lst) = tmp;
        return 1;
}


int pop(queue *lst)
{
        queue tmp =(*lst) -> prev;
        free((*lst));
        (*lst)=tmp;
        return 1;
}

int view (queue *lst)
{
        queue x;
        x = *lst;
        while( x != NULL)
        {
                printf("%d",(x)->data);
                printf(" ");
                (x) = (x) -> next;
        }
        printf("\n");
        return 1;
}

int size(queue *lst)
{
        int z=0;
        queue x;
        x = *lst;
        while( x != NULL)
        {
                z=z+1;
                (x) = (x) -> next;
        }
        printf("\n");
        return z;

}

