#include<bits/stdc++.h>
using namespace std;
int matrix[100][100],v;
int rev_matrix[100][100];
char color[100];
stack<int>S;
void dfs_visit1(int x)
{
    color[x]='G';
    for(int i=1;i<=v;i++)
    {
        if(rev_matrix[x][i]==1 && color[i]=='W')
        {
            dfs_visit1(i);
        }
    }
    color[x]='B';
    cout<<" "<<x;
}
void dfs_visit(int x)
{
    color[x]='G';
    for(int i=1;i<=v;i++)
    {
        if(matrix[x][i]==1 && color[i]=='W')
        {
            dfs_visit(i);
        }
    }
    color[x]='B';
    S.push(x);
}
void dfs()
{
    for(int i=1;i<=v;i++)
    {
        color[i]='W';
    }
    for(int i=1;i<=v;i++)
    {
        if(color[i]=='W')
        {
            dfs_visit(i);
        }
    }
}
void scc()
{
    for(int i=1;i<=v;i++)
    {
        color[i]='W';
    }
    while(!S.empty())
    {
        if(color[S.top()]=='W')
        {
            dfs_visit1(S.top());
            cout<<endl;
        }
        S.pop();
    }
}
int main()
{

   int e1,e2,counter=1;

    cout<<"Enter number of Vartex : ";
    cin>>v;

    while(1)
    {
        cout<<"Edge "<<counter<<" : ";

        cin>>e1>>e2;

        if(e1>v || e2>v)
        {
            cout<<"Wrong input"<<endl;
        }
        else if(e1==0 && e2==0)
        {
            break;
        }
        else
        {
            matrix[e1][e2]=1;
            rev_matrix[e2][e1]=1;
            counter++;
        }
    }
    dfs();
    scc();

}
