#include<bits/stdc++.h>
#include<list>
#include<queue>
#include<iostream>
using namespace std;
int graph[10][10]= {false};
bool visit[100];
int counter[10];
int n,v;
list<int>adj[100];
list<int>::iterator p;
queue<int>Q;
void bfs1(int s)
{
    int  dis[v+1],prev[v+1];
    char color[v+1];
    int u;
    for(int i=1;i<=v;i++)
    {
        color[i]='W';
        dis[i]=(1.0/0.0);
        prev[i]=-1;
    }
    color[s]='G';
    dis[s]=0;
    prev[s]=-1;
    Q.push(s);
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        for(int i=1;i<=v;i++)
        {
            if(graph[u][i]==1 && color[i]=='W')
            {
                Q.push(i);
                color[i]='G';
                dis[i]=dis[u]+1;
                prev[i]=u;
            }
        }
        color[u]='B';
    }
    cout<<"   Color "<<"   Distance  "<<"  Previous "<<endl;
    for(int i=1;i<=v;i++)
    {
        cout<<i<<":    "<<color[i]<<"         "<<dis[i]<<"        "<<prev[i]<<endl;
    }
    cout<<endl;
    int maxn,c=0;
    maxn=dis[0];
    for(int i=1;i<=v;i++)
    {
        if(maxn<dis[i])
        {
            maxn=dis[i];
            c=i;
        }
    }
    cout<<endl<<"Maximum Distance from "<<s<<" to "<<c<<" : "<<maxn<<endl;

}

void bfs2(int s)
{
    int  dis[v+1],prev[v+1];
    char color[v+1];
    int u;
    for(int i=1;i<=v;i++)
    {
        color[i]='W';
        dis[i]=(1.0/0.0);
        prev[i]=-1;
    }
    color[s]='G';
    dis[s]=0;
    prev[s]=-1;
    Q.push(s);
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        for(int i=1;i<=v;i++)
        {
          for(p=adj[i].begin();p!=adj[i].end(); p++)
          {
            if(color[*p]=='W')
            {
                Q.push(*p);
                color[*p]='G';
                dis[*p]=dis[u]+1;
                prev[*p]=u;
            }
          }
        }
        color[u]='B';
    }
    cout<<"   Color "<<"   Distance  "<<"  Previous "<<endl;
    for(int i=1;i<=v;i++)
    {
        cout<<i<<":    "<<color[i]<<"         "<<dis[i]<<"        "<<prev[i]<<endl;
    }
    cout<<endl;
    int maxn,c=0;
    maxn=dis[0];
    for(int i=1;i<=v;i++)
    {
        if(maxn<dis[i])
        {
            maxn=dis[i];
            c=i;
        }
     }
    cout<<endl<<"Maximum Distance from "<<s<<" to "<<c<<" : "<<maxn<<endl;

}
int main()
{
    int e1=1,e2=1;
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
    cout<<"Enter the starter vertex : ";
    cin>>x;
    if(x>v && x<0)
    {
        cout<<"Wrong key"<<endl;
    }
    else
    {
        cout<<endl<<"----Print using Matrix----"<<endl;
         bfs1(x);
        cout<<endl<<"----Print using List------"<<endl;
        bfs2(x);
    }
    return 0;
}
