#include<bits/stdc++.h>
using namespace std;
int v;
int main()
{
     int a,b,counter=1;
     cout<<"Enter vertex : ";
     cin>>v;
     bool adj[v+1][v+1];
     for(int i=0;i<=v;i++)
     {
         for(int j=0;j<=v;j++)
         {
             adj[i][j]==0;
         }
     }
     while(1)
     {
        cout<<"Edge "<<counter<<" : ";
        cin>>a>>b;

        if(a>v || b>v)
        {
            cout<<"Wrong input"<<endl;
        }
        else if(a==0 && b==0)
        {
            break;
        }
        else
        {
            adj[a][b]=1;
            counter++;
        }
    }
    int n=0;
    for(int i=0;i<=v;i++)
    {
        int c1=0,c2=0;
        for(int j=0;j<=v;j++)
        {
            if(adj[j][i]==1)
            {
                c1++;
            }
            if(adj[i][j]==1)
            {
                ++c2;
            }
        }
    if(c1==v-1 && c2==0)
    {
        cout<<"Universal Sink is : "<<i<<endl;
        n=1;
        break;
     }
   }
   if(n==0)
   {
       cout<<"No Universal sink"<<endl;
   }
   return 0;
}
