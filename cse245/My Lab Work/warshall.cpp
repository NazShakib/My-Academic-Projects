//Nazmus Sakib Patwary
//2015-2-60-092
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int matrix[100][100],v;
void warshall()
{
    int i,j,k;
     for (int i=1; i<=v; i++)
    {
        for (int j=1; j<=v; j++)
        {
            for (int k=1; k<=v; k++)
            {
                if (matrix[j][i] + matrix[i][k] < matrix[j][k])
                    matrix[j][k] = matrix[j][i] + matrix[i][k];
            }
        }
    }
}
void display()
{
    int i,j;
     for (int i=1; i<=v; i++)
    {
        for (int j=1; j<=v; j++)
            printf("%d\t",matrix[i][j]);
        printf("\n");
    }
}
int main()
{
    int e1,e2,w,i,j;
    printf("Enter Number of Vertex : ");
    scanf("%d",&v);
    for (int i=1; i<=v; i++)
    {
        for (int j=1; j<=v; j++)
        {
            if (i == j)
                matrix[i][j] = 0;
            else
                matrix[i][j] =999999;
        }
    }
    i=1;
    while(1)
    {
        printf("Edge & weight %d : ",i);
        scanf("%d %d %d",&e1,&e2,&w);
        if(e1==0 && e2==0 && w==0)
        {
            break;
        }
        if(v>=e1 && v>=e2)
        {
           matrix[e1][e2]=w;
        }
        else
        {
            cout<<"Invalid Key "<<endl;
            i--;
        }
        i++;
    }
    warshall();
    printf("\nOutput is:\n\n");
    display();
    return 0;
}
