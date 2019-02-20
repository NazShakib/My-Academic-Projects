#include<bits/stdc++.h>
using namespace std;
int v,graph[10][10];
int dis[10],prev[10],fnal[10];
char color[10];
int t=0;

void dfs_visit1(int s)
{
    color[s]='G';
    t++;
    dis[s]=t;
    for(int i=1; i<=v; i++)
    {
        if(graph[s][i]==1 && color[i]=='W')
        {
            prev[i]=s;
            dfs_visit1(i);
        }
    }
    color[s]='B';
    t++;
    fnal[s]=t;
   // cout<<s<<" :          "<<dis[s]<<"                   "<<fnal[s]<<"               "<<prev[s]<<endl;
}
void print()
{
    cout<<"Node   "<<" Starting time   "<<" Finishing time   "<<"  Previous "<<endl;
    for(int i=1; i<=v; i++)
    {
        cout<<i<<" :          "<<dis[i]<<"                   "<<fnal[i]<<"               "<<prev[i]<<endl;
    }
    cout<<endl;
}
void dfs1(int s)
{
    int u;
    for(int i=1; i<=v; i++)
    {
        color[i]='W';
        dis[i]=(1.0/0.0);
        fnal[i]=(1.0/0.0);
        prev[i]=-1;
    }
    dfs_visit1(s);
    for(int i=1; i<=v; i++)
    {
        if(color[i]=='W' && i!=s)
        {
            dfs_visit1(i);
        }
        //s++;
    }
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
            graph[x][y]=1;//graph[y][x]=1;
          //  adj[x].push_back(y);
            //adj[y].push_back(x);
        }
        else
        {
            cout<<"Invalid Key "<<endl;
            i--;
        }
        i++;
    }

   /* cout<<"Enter the starter vertex : ";
    cin>>x;
    if(x>v && x<0)
    {
        cout<<"Wrong key"<<endl;
    }
    else
    {*/
        cout<<endl<<"----Print using Matrix----"<<endl;
        dfs1(1);
        print();
    //}

    return 0;
}
