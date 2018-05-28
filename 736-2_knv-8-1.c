#include <stdio.h>
#include <stdlib.h>

void QuickSort(int* array, int first, int last)
{
    int i = first, j = last, x = array[(first + last) / 2];
  
    do {
        while (array[i] < x) i++;
        while (array[j] > x) j--;
  
        if(i <= j) {
            if (array[i] > array[j])
		{
			int tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
            	}
	    i++;
            j--;
        }
    } while (i <= j);
  
    if (i < last)
        QuickSort(array, i, last);
    if (first < j)
        QuickSort(array, first, j);
}
int main()
{
	int n;
	scanf("%d", &n);
	int *array = malloc(sizeof(int[n]));
        for (int i=0; i<n; ++i)
        {
                scanf("%d",&array[i]);
                printf("%d ", array[i]);
        }
        printf("\n");
	QuickSort(array,0,n-1);
	for (int i=0; i<n; ++i)
        {
                printf("%d ",array[i]);
        }
        printf("\n");
	free(array);
	return 0;
}
