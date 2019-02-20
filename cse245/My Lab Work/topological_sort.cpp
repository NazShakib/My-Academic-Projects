#include<bits/stdc++.h>
using namespace std;
int adj[100][100],v,t,s[100],f[100],prev[100];
char color[100];
stack<int>S;
void dfs_visit(int m)
{
    t++;
    s[m]=t;
    color[m]='G';
    for(int i=1; i<=v; i++)
    {
        if(adj[m][i]==1 && color[i]=='W')
        {
            prev[i]=m;
            dfs_visit(i);
        }
    }
    color[m]='B';
    t++;
    f[m]=t;
    S.push(m);
}
void dfs()
{
    for(int i=1; i<=v; i++)
    {
        color[i]='W';
        prev[i]=-1;
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
            adj[x][y]=1;
        }
        else
        {
            cout<<"wrong key"<<endl;
            i--;
        }
        i++;
    }
    dfs();
    int c=0;
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            if(adj[i][j]==1)
            {
                if(s[i]>s[j] && f[i]<f[j])
                {
                    c++;
                }
            }
        }
    }
    if(c==0)
    {
    cout<<"Topological sort : ";
    while(!S.empty())
    {
        cout<<S.top()<<"  ";
        S.pop();
    }
    cout<<endl;
    }
    else
    {
        cout<<"cycle found"<<endl;
    }
    return 0;
}
