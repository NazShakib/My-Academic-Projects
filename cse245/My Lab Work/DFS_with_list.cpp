#include<bits/stdc++.h>
#include<list>
using namespace std;

int v;
int t=0;
int start[100],finish[100],prev[100];
char color[100];
void dfs_visit(int s,list<int>*adj)
{
    color[s]='G';
    start[s]=t++;
    list<int>::iterator p;
    for(p=adj[s].begin();p!=adj[s].end();p++)
    {
        if(color[*p]=='W')
        {
            prev[*p]=s;
            dfs_visit(*p,adj);
        }
    }
    t++;
    finish[s]=t;
    color[s]='B';
   // cout<<s<<": Starting time : "<<start[s]<<"   Finishing time : "<<finish[s]<<"  Color : "<<color[s]<<"  Previous : "<<prev[s]<<endl;
}
void dfs2(int s ,list<int>*adj)
{
    for(int i=1;i<=v;i++)
    {
        color[i]='W';
        prev[i]=-1;
        start[i]=(1.0/0.0);
        finish[i]=(1.0/0.0);
    }
    dfs_visit(s,adj);
    for(int i=1;i<=v;i++)
    {
        if(color[i]=='W' && i!=s)
        {
            dfs_visit(i,adj);
        }
    }
}
void print()
{
    cout<<"Node   "<<" Starting time   "<<" Finishing time   "<<"  Previous "<<endl;
    for(int i=1; i<=v; i++)
    {
        cout<<i<<" :          "<<start[i]<<"                   "<<finish[i]<<"               "<<prev[i]<<endl;
    }
    cout<<endl;
}
int main()
{
    list<int>adj[10];
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
          // graph[x][y]=graph[y][x]=1;
           adj[x].push_back(y);
           //adj[y].push_back(x);
       }
       else
        {
           cout<<"Invalid Key "<<endl;
           i--;
       }
       i++;
    }

    int s;
    //cout<<"Enter starter vertex : ";
    //cin>>s;
    //if(s>v || s<0)
    //{
      //  cout<<"Invalid key !"<<endl;
    //}
    //else
    //{
        cout<<"-----Print using list---- "<<endl;
        dfs2(1,adj);
        print();
   // }
}
