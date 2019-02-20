#include<bits/stdc++.h>
using namespace std;
int v,t,s[100],f[100],prev[100];
char color[100];
int adj[100][100];
void dfs_visit(int x)
{
    color[x]='G';
    t++;
    s[x]=t;
    for(int i=1; i<=v; i++)
    {
        if(adj[x][i]==1 && color[i]=='W')
        {
            prev[i]=x;
            dfs_visit(i);
        }
    }
    color[x]='B';
    t++;
    f[x]=t;
}
void dfs()
{
    int i;
    for(i=1; i<=v; i++)
    {
        s[i]=(1.0/0.0);
        f[i]=(1.0/0.0);
        prev[i]=-1;
        color[i]='W';
    }
    t=0;
    for(i=1; i<=v; i++)
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
            adj[y][x]=1;
        }
        else
        {
            cout<<"wrong key"<<endl;
            i--;
        }
        i++;
    }
    dfs();
    cout<<"Tree Edges : ";
    int c1=0;
    for(int i=1; i<=v; i++)
    {
        for(int j=1; j<=v; j++)
        {
            if(adj[i][j]==1)
            {
                if( s[i]<s[j] && f[i]>f[j] && prev[j]==i)
                {
                    c1++;
                    cout<<i<<"  "<<j<<endl;
                }
            }
        }
    }
    cout<<endl<<"total tree edges : "<<c1<<endl;
    cout<<"Cross Edges : ";
    int c2=0;
    for(int i=1; i<=v; i++)
    {
        for(int j=1; j<=v; j++)
        {
            if(adj[i][j]==1)
            {
                if(s[i]>s[j] && f[i]>f[j])
                {
                    c2++;
                    cout<<i<<"  "<<j<<endl;
                }
            }
        }
    }
    cout<<endl<<"Total cross edges : "<<c2<<endl;

    cout<<"Forward Edges : ";
    int c3=0;
    for(int i=1; i<=v; i++)
    {
        for(int j=1; j<=v; j++)
        {
            if(adj[i][j]==1)
            {
                if(s[i]<s[j] && f[i]>f[j] && prev[j]!=i)
                {
                    c3++;
                    cout<<i<<"  "<<j<<endl;
                }
            }
        }
    }
    cout<<endl<<"Total forward edges : "<<c3<<endl;
    cout<<"Back Edges : ";
    int c4=0;
    for(int i=1; i<=v; i++)
    {
        for(int j=1; j<=v; j++)
        {
            if(adj[i][j]==1)
            {
                if(s[i]>s[j] && f[i]<f[j] && prev[i]!=j)
                {
                    c4++;
                    cout<<i<<"  "<<j<<endl;
                }
            }
        }
    }
    cout<<endl<<"Total back edges : "<<c4<<endl;
}
