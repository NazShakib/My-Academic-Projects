#include <bits/stdc++.h>
using namespace std;
int v,color[100];
bool graph[100][100];
bool isBipartite(int s)
{
    color[s] = 1;
    queue <int> Q;
    Q.push(s);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if (graph[u][u] == 1)
        {
           return false;
        }
       for (int i = 1; i <=v; ++i)
        {
            if (graph[u][i] && color[v] == -1)
            {
                color[i] = 1 - color[u];
                Q.push(i);
            }
            else if (graph[u][i] && color[i] == color[u])
            {
                return false;
            }
        }
    }
    return true;
}
bool Bipartite()
{
    for (int i = 1; i <=v; ++i)
    {
        color[i] = -1;
    }
   for (int i = 1; i <=v; i++)
    {
      if (color[i] == -1)
      {
        if (isBipartite(i) == false)
        {
           return false;
         }
      }
    }

     return true;
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
        }
        else
        {
            cout<<"Invalid Key "<<endl;
            i--;
        }
        i++;
    }
    Bipartite() ? cout << "Yes" : cout << "No";
    return 0;
}
