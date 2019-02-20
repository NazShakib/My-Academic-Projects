//Nazmus sakib patwary
//2015-2-60-092
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;
vector<int>array[100];
int matrix[100][100],cost[100],prev[100],v;
int Bellman_ford()
{
    int i,j,k;
        for (i=1; i<=v-1; i++)
    {
        for (j=1; j<=v; j++)
        {
            for (vector< int > :: iterator p= array[j].begin(); p != array[j].end(); p++)
            {
                if (cost[j] + matrix[j][*p] < cost[*p])
                {
                    cost[*p] = cost[j] + matrix[j][*p];
                    prev[*p] = j;
                }
            }
        }
    }
    for (k=1; k<=v; k++)
    {
        for (vector < int > :: iterator p= array[k].begin(); p != array[k].end(); p++)
        {
            if (cost[k] + matrix[k][*p] < cost[*p])
            {
                return -1;
            }
        }
    }
    return 1;
}
int main()
{
    int e1,e2;
    int i,j,w;
    printf("Enter Number of Vertex : ");
    scanf("%d",&v);
    i=1;
    while(1)
    {
        printf("Edge %d : ",i);
        scanf("%d %d %d",&e1,&e2,&w);
        if(e1==0 && e2==0 && w==0)
        {
            break;
        }
        if(v>=e1 && v>=e2)
        {
            array[e1].push_back(e2);
            matrix[e1][e2]=w;
        }
        else
        {
            cout<<"Invalid Key "<<endl;
            i--;
        }
        i++;
    }
    for (i=1; i<=v; i++)
    {
        cost[i] = 999999;
        prev[i] = -1;
    }
    int n;
    printf("Enter source node : ");
    scanf("%d",&n);
    cost[n]=0;
    prev[n]=-1;
    if(Bellman_ford()==-1)
    {
        printf("Negative cycle found\n");
    }
    else
    {
        printf("Node\tCost\tPrevious\n");
        for (i=1; i<=v; i++)
        {
           printf("%d\t%d\t%d\n",i,cost[i],prev[i]);
        }
    }
    return 0;
}
