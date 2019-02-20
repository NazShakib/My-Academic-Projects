#include<bits/stdc++.h>
using namespace std;
int v,adj[100][100];
void cheek()
{
    int c;
    for(int i=1;i<=v;i++)
    {
        c=0;
        for(int j=1;j<=v;j++)
        {
            if(adj[i][j]==1 && adj[j][i]==1 && i!=j)
            {
                c++;
            }
        }
    }
    if(c==v-1)
    {
        cout<<endl<<"Complete"<<endl;
    }
    else
    {
        cout<<endl<<"Not Complete"<<endl;
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
    cheek();
}
