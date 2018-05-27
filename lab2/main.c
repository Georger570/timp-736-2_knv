#include <stdio.h>
#include <stdlib.h>
#include "graph.c"

int pathSearch(graph a, int pos)
{
    graph G=a;
    while((G !=NULL))
    {
        if ((G -> peak) == pos)
            break;
        G = G -> nextpeak;
    }
    return 1;
}

int main()
{
    graph a;
    graphInit(&a);
    graphConstruction(&a);
    graph b = a;
    while(b != NULL)
    {
        way abc = (b -> pod);
        printf(" %d", b ->peak);
        printf("\n");
        while(abc != NULL)
        {
            printf("  %d", abc -> peak);
            //printf("  %p", abc -> peaklocation);
            //printf("  %p", b);
            printf(" %d", abc -> weight);
            printf("\n");
            abc = (abc -> next);
        }
        b = b -> nextpeak;
    }
    return 0;
}
