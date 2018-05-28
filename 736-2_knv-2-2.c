#include <stdio.h>

int main()
{
	int k=0,n=0, g=0, x=0, xp;
	scanf("%d", &n);
	while (k<n)
	{
		xp=x;  
		scanf("%d", &x);
		if (k==0)
		{
			k=k+1;
			continue;
		}
		else
		{
			k=k+1;
			if (x>=xp) 
			{
				g=1;
				printf("0\n");
				return 0;
			}
		}
	}
	if ( g==0)
	{
		printf("1\n");
	}
	return 0;
}
