#include <stdio.h>
#include <stdlib.h>

typedef struct waynode
{
    struct waynode *next;
    struct peaknode *peaklocation;
    int peak;
    int weight;
} waynode;

typedef waynode* way;

typedef struct peaknode
{
    int peak;
    way pod;
    struct peaknode* nextpeak;
} peaknode;

typedef peaknode *graph;

int graphInit(graph *a)
{
    *a = NULL;
    return 1;
}

int graphPeakReading(int *peak, int *quantity, int **pod, int **weight )
{
    int a,b;
    scanf("%d", &(*peak));
    scanf("%d", &(*quantity));
    *pod = (int*) calloc(*quantity, sizeof(int));
    *weight = (int*) calloc(*quantity, sizeof(int));
    for (int i = 0; i<(*quantity); ++i)
    {
        scanf("%d", &a);
        (*pod)[i] = a;
        scanf("%d", &b);
        (*weight)[i] = b;
    }
    return 1;
}

int graphPeakConstruction(graph *a,int peak, int quantity, int **pod, int **weight)
{
    graph tmp = malloc(sizeof(peaknode));
    tmp -> peak = peak;
    tmp -> nextpeak = NULL;
    tmp -> pod = NULL;
    way wtmp = calloc(quantity,sizeof(waynode));
    for (int i=0; i<quantity; ++i)
    {
        wtmp[i].peak = (*pod)[i];
        wtmp[i].weight = (*weight)[i];
        if (i<quantity-1)
            wtmp[i].next = &wtmp[i+1];
        else
            wtmp[i].next = NULL;
    }
    tmp -> pod = wtmp;
    if (*a == NULL)
        *a=tmp;
    else
    {
        graph c = (*a);
        graph *atmp = a;
        while ( (*atmp) -> nextpeak != NULL)
            (*atmp) = ( (*atmp) -> nextpeak);
        ((*atmp) -> nextpeak) = tmp;
        (*a) = c;

    }
    return 1;
}

int graphTie(graph *a)
{
    graph g = (*a);
    while (g != NULL)
    {
        way w = g -> pod;
        graph c = (*a);
        while (w != NULL)
        {
            while(c != NULL)
            {
                if (c->peak == w->peak)
                {
                    w -> peaklocation = c;
                    break;
                }
                c = c -> nextpeak;
            }
            w = w->next;
        }
        g=g->nextpeak;
    }
    return 1;
}

int graphConstruction(graph *a)
{
    int n=0;
    int peak=0;
    int quantity=0;
    int *pod=0;
    int *weight=0;
    scanf ("%d",&n);
    for (int i=0; i<n; ++i)
    {
        graphPeakReading(&peak, &quantity, &pod, &weight);
        graphPeakConstruction(a, peak, quantity, &pod, &weight);
    }
    graphTie(a);
    return 1;
}
