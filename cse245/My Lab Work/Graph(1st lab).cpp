#include<bits/stdc++.h>
#include<list>
#include<iostream>
using namespace std;
int graph[10][10]= {false};
int counter[10];
int n;
list<int>adj[100];
list<int>::iterator p;
int main()
{
    int v,e1=1,e2=1;
    int x,y,i,j;
    printf("Enter Number of Vertex : ");
    scanf("%d",&v);
    i=1;
    while(1)
    {
        printf("Edge %d : ",i);
        scanf("%d %d",&e1,&e2);
        if(e1==0 && e2==0)
        {
            break;
        }
        if(v>=e1 && v>=e2)
        {
            x=e1;
            y=e2;
            graph[x][y]=graph[y][x]=1;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        else
        {
            cout<<"Invalid Key "<<endl;
            i--;
        }
        i++;
    }

    cout<<"Print Adjancy matrix"<<endl;
    cout<<endl;
    for(i=1; i<=v; i++)
    {
        for(j=1; j<=v; j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Print List Graph "<<endl;
    cout<<endl;
    for(i=1; i<=v; i++)
    {
        printf("adj[%d] : ",i);
        for(p=adj[i].begin(); p!=adj[i].end(); p++)
        {
            cout<<*p<<" ";
        }
        cout<<endl;
    }

    cout<<"Enter a vertex Number : ";
    cin>>n;
    int c=0;
    cout<<endl<<"Direct Link with : ";
    for(i=1; i<=v; i++)
    {
        if(graph[n][i]==1)
        {
            c++;
            cout<<i<<" ";
        }
    }
    cout<<endl;
    cout<<endl<<"Total connected node : "<<c<<endl;
    cout<<endl<<"Total Out Degree : "<<c<<endl;
    cout<<endl<<"Total In Degree : "<<c<<endl;
    loop1:cout<<endl<<"Enter two vertex : ";
    cin>>e1>>e2;
    if(e1>v || e2>v)
    {
        cout<<"invalid key "<<endl;
        goto loop1;
    }
    else
    {
        goto loop2;
    }
    loop2: if(graph[e1][e2]==1)
    {
        cout<<"Yes!They are connected "<<endl;
    }
    else
    {
        cout<<"Not connected "<<endl;
    }
    return 0;
}
