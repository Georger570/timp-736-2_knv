#include "queue.h"

int main()
{
	push(&back,1);
//	printf("%d\n", back -> data);
	push(&back,2);
//	printf("%d\n", back -> data);
	push(&back,3);
//	printf("%d\n", back -> data);
        push(&back,4);
	push(&back,5);
        push(&back,6);
	view(&top);
	printf("%d\n", size(&top));
	printf("%d\n", top -> data);
	printf("%d\n", back -> data);
	pop(&top);
	printf("%d\n", size(&top));
	view(&top);
	destroy(&top);
	if( isEmpty(top) == true)
	{
	printf("true\n");
	}
	return 0;
}


	
