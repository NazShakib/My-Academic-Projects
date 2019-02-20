#include<bits/stdc++.h>
using namespace std;

int matrix[100][100];
int d[100];
int v;

struct edge
{
    int node;
    int dis;

    bool operator < (const edge& p) const
    {
        return dis>p.dis;
    }
};

void dijkstra(int s)
{
    priority_queue<edge> p;

    for(int i=1;i<=v;i++)
    {
        d[i]=1000000;
    }

    d[s]=0;

    edge temp;

    temp.dis=0;
    temp.node=s;

    p.push(temp);

    while(!p.empty())
    {
        temp=p.top();
        p.pop();

        for(int i=1;i<=v;i++)
        {
            if(matrix[temp.node][i]!=0)
            {
                edge temp1;

                temp1.node=i;
                temp1.dis=d[temp.node]+matrix[temp.node][i];

                if(d[i]>temp1.dis)
                {
                    d[i]=temp1.dis;
                    p.push(temp1);
                }
            }
        }
    }
}

int main()
{
    int a,b,w,count=1;

    cout<<"Enter number of Vartex : ";
    cin>>v;

    while(1)
    {
        cout<<"Edge "<<count<<" : ";

        cin>>a>>b>>w;

        if(a>v || b>v)
        {
            cout<<"Wrong input"<<endl;
        }
        else if(a==0 && b==0 && w==0)
        {
            break;
        }
        else
        {
            matrix[a][b]=w;
            count++;
        }
    }

    dijkstra(1);
 cout<<"\tNode\tDistance"<<endl;
    for(int i=1;i<=v;i++)
    {
        cout<<"1 to  \t"<<i<<"\t"<<d[i]<<endl;
    }
    return 0;
}
