#include<bits/stdc++.h>
using namespace std;
list<int>adj[100];
vector<int>name;
int start[100],finish[100],prev[100],low[100];
char color[100];
int t,v;
void dfs_visit(int s)
{
    int n=0;
    color[s]='G';
    t++;
    start[s]=t;
    low[s]=start[s];
    for(list<int>::iterator p=adj[s].begin(); p!=adj[s].end(); p++)
    {
        if(color[*p]=='W')
        {
            n++;
            prev[*p]=s;
            dfs_visit(*p);

            low[s]=min(low[s],low[*p]);

            if(prev[s]==-1 && n>1)
            {
                name.push_back(s);
            }
            if(low[*p]>=start[s] && prev[s]!=-1)
            {
                name.push_back(s);
            }
        }
        else if(*p!=prev[s])
        {
            low[s]=min(low[s],start[*p]);
        }
    }
    color[s]='B';
    t++;
    finish[s]=t;
}
void dfs()
{
    for(int i=1; i<=v; i++)
    {
        color[i]='W';
        start[i]=1000000;
        finish[i]=1000000;
        prev[i]=-1;
        low[i]=10000000;
    }
    t=0;
    for(int i=1; i<=v; i++)
    {
        if(color[i]=='W')
        {
            dfs_visit(i);
        }
    }
}
int main()
{
    int e1,e2,i=1,x,y;
    cout<<"Enter vertex number : ";
    scanf("%d",&v);
    while(1)
    {
        printf("Edge %d : ",i);
        scanf("%d %d",&e1,&e2);
        x=e1,y=e2;
        if(x==0 && y ==0 )
        {
            break;
        }
        else if(v>=e1 && v>=e2)
        {
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        else
        {
            cout<<"wrong key"<<endl;
            i--;
        }
        i++;
    }
    dfs();
    int c=0,c1=0;
    for(i=0; i<name.size(); i++)
    {
        if(c1==0)
        {
            cout<<"Articulation point are : ";
            c1=5;
        }
          cout<<name[i]<<" ";
        c++;
    }
    if(c==0)
    {
        cout<<"No articulation point"<<endl;
    }
    return 0;
}
