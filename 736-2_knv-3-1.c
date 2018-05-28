#include "spisok.h"

int main()
{
	init(&head);
	int i,n,k,m,c,d;
	int data;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &data);
		append(&tail, data);
	}
	print(&head);
	scanf("%d", &k);
	removeposition(&head, k);
	print(&head);
	scanf("%d", &m);
	list mv=find(head, m);
	removeit(&mv);
	mv = NULL;
	print(&head);
	scanf("%d",&c);
	scanf("%d",&d);
	mv = head;
	for (i=1; i<(c); i++)
	{
		mv = (mv -> next);
	}
	prepend(&mv, d);
	mv = NULL;
	print(&head);
	destroy(&head);	
	return 0;
}
