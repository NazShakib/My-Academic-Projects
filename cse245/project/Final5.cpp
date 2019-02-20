//      East West University

//      Semester Project of CSE 245 (Algorithm) Course
//      Summer 2017
//      Section: 2

//      Digital Zoo Management

//      Nazmus Sakib Patwary (2015-2-60-092)
//      Md. Shahbaz Sasik (2015-2-60-067)
//      Md. Tanvir Hossain (2015-2-60-113)

#include <bits/stdc++.h>
using namespace std;

vector < string > node_name, backtrack, storepath[100][100], mintime[100][100];
vector < int > store[100], weight[100];
int cost[100], path_time[100][100], pathprevious[100], node_number, path_distance[100][100], dataprevious[100], value[100];
int source, mask_path[100][100], temp, temp1, temp2, path_store[100][100], mask2_path[100][100], data[100], mask_time[100];
int matrix[100][100], d[100],prev[100], v, l, m, limtime, trigger[100][100], keep1, keep2, check[100][100], siz, grid[100][100];
int time_store[100][100], false_time[100][100], takemintime[100][100], node_time[100];
string here, there;
stack < string > namestore[100];


int W, n, K[100][100], prevee[100][100], take11, take21;

struct edge1
{
    int node;
    int distance;
    bool operator < (const edge1& p) const
    {
        return distance>p.distance;
    }
};

void dijkstra(int source,int m_mat[][100] )
{
    priority_queue<edge1> p;
    v=node_number;
    for(int i=1; i<=v; i++)
    {
        d[i]=1000000;
        prev[i]=-1;
    }
    d[source]=0;
    edge1 temp;
    temp.distance=0;
    temp.node=source;
    p.push(temp);
    while(!p.empty())
    {
        temp=p.top();
        p.pop();
        for(int i=1; i<=v; i++)
        {
            if(m_mat[temp.node][i]!=0)
            {
                edge1 t;

                t.node=i;
                t.distance=d[temp.node]+m_mat[temp.node][i];

                if(d[i]>t.distance)
                {
                    d[i]=t.distance;
                    d[i]+=d[temp.node];
                    prev[i]=temp.node;
                    p.push(t);
                }
            }
        }
    }
}

void pathprint(int l, int m)
{
    int i;
    for(i=m; ; i=prev[i] )
    {
        if(l==i)
            break;
        namestore[l].push(node_name[i-1]);
    }
}

void printpath(int takepath[][100], int v, int u, int flag)
{
    storepath[v][flag].push_back(node_name[u]);
    if (takepath[v][u] == v)
        return;

    printpath(takepath, v, takepath[v][u], flag);
    //cout << takepath[v][u] << " ";
}

void printpath2(int takepath[][100], int v, int u, int flag)
{
    mintime[v][flag].push_back(node_name[u]);
    if (takepath[v][u] == v)
        return;

    printpath(takepath, v, takepath[v][u], flag);
    //cout << takepath[v][u] << " ";
}

void solution(int take1[100][100], int take2[100][100])
{
    for (int v=0; v<node_number; v++)
    {
        for (int u=0; u<node_number; u++)
        {
            if (u != v && take2[v][u] != -1)
            {
                //cout << "Shortest Path from vertex " << v <<
                  //   " to vertex " << u << " is (" << v << " ";
                printpath(take2, v, u, u);
               // cout << u << ")" << endl;
            }
        }
    }
}

void solution2(int take1[100][100], int take2[100][100])
{
    for (int v=0; v<node_number; v++)
    {
        for (int u=0; u<node_number; u++)
        {
            if (u != v && take2[v][u] != -1)
            {
              //  cout << "Shortest Path from vertex " << v <<
              //       " to vertex " << u << " is (" << v << " ";
                printpath2(take2, v, u, u);
                //cout << u << ")" << endl;
            }
        }
    }
}

void warshall()
{
    for (int v=0; v<node_number; v++)
    {
        for (int u=0; u<node_number; u++)
        {
            if (v == u)
                path_store[v][u] = 0;
            else if (mask_path[v][u] != INT_MAX)
                path_store[v][u] = v;
            else
                path_store[v][u] = -1;
        }
    }

    for (int k=0; k<node_number; k++)
    {
        for (int v=0; v<node_number; v++)
        {
            for (int u=0; u<node_number; u++)
            {
                if (mask_path[v][k] != INT_MAX  && mask_path[k][u] != INT_MAX && mask_path[v][k] + mask_path[k][u] < mask_path[v][u])
                {
                    mask_path[v][u] = mask_path[v][k] + mask_path[k][u];
                    path_store[v][u] = path_store[k][u];
                }
            }
        }
    }
    solution(mask_path, path_store);
}

void warshall2()
{
    for (int v=0; v<node_number; v++)
    {
        for (int u=0; u<node_number; u++)
        {
            if (v == u)
                time_store[v][u] = 0;
            else if (false_time[v][u] != INT_MAX)
                time_store[v][u] = v;
            else
                time_store[v][u] = -1;
        }
    }

    for (int k=0; k<node_number; k++)
    {
        for (int v=0; v<node_number; v++)
        {
            for (int u=0; u<node_number; u++)
            {
                if (false_time[v][k] != INT_MAX  && false_time[k][u] != INT_MAX && false_time[v][k] + false_time[k][u] < false_time[v][u])
                {
                    false_time[v][u] = false_time[v][k] + false_time[k][u];
                    time_store[v][u] = time_store[k][u];
                }
            }
        }
    }
    solution2(false_time, time_store);
}

void takename()
{
    node_name.push_back("Birds Home");
    node_name.push_back("Ostrich");
    node_name.push_back("Flamingo");
    node_name.push_back("Peacock");
    node_name.push_back("Gray Parrot");
    node_name.push_back("Macaw");
    node_name.push_back("Cockatoo");
    node_name.push_back("Penguin");
    node_name.push_back("Mandrill");
    node_name.push_back("White Headed Capuchin");
    node_name.push_back("Emperor Tamarin");
    node_name.push_back("Baboon");
    node_name.push_back("Ape");
    node_name.push_back("Monkey");
    node_name.push_back("Lion");
    node_name.push_back("Salt Water Crocodile");
    node_name.push_back("Fresh Water Crocodile");
    node_name.push_back("The Royle Bengal Tiger");
    node_name.push_back("Leopard");
    node_name.push_back("Grizzly Bear");
    node_name.push_back("Jaguar");
    node_name.push_back("Wolfe");
    node_name.push_back("Hayena");
    node_name.push_back("Alligator");
    node_name.push_back("Black Mamba");
    node_name.push_back("King Cobra");
    node_name.push_back("Viper");
    node_name.push_back("Tiger Snake");
    node_name.push_back("Anaconda");
    node_name.push_back("Python");
    node_name.push_back("Cemophora");
    node_name.push_back("Rattlesnake");
    node_name.push_back("Coffee Shop");
    node_name.push_back("Washroom");
    node_name.push_back("Giraffe");
    node_name.push_back("Hippopotomus");
    node_name.push_back("Zebra");
    node_name.push_back("Rhinoceros");
    node_name.push_back("Deer");
    node_name.push_back("American Bison");
    node_name.push_back("African Buffalo");
    node_name.push_back("Kangaroo");
    node_name.push_back("Wildebeest");
    node_name.push_back("Elephant");
    node_name.push_back("Okapi");
    node_name.push_back("Giant Panda");
    node_name.push_back("Guinea Pig");
    node_name.push_back("Washroom");
    node_name.push_back("Museum");
    node_name.push_back("Exit");
}


int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   for (i = 1; i <= n; i++)
   {
       for (w = 1; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
           {
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
                 if ((val[i-1] + K[i-1][w-wt[i-1]]) > (K[i-1][w]))
                 {
                        check[i][w] = 1;
                        prevee[i][w] = w-wt[i-1];
                 }
                 else
                    prevee[i][w] = w;
           }
           else
           {
               prevee[i][w] = w;
                K[i][w] = K[i-1][w];
           }
       }
   }

   return K[n][W];
}

int main()
{
    int option, from, too, number, time2, weight, time3;
    string take1, take2;
    FILE *first = fopen("input.txt", "r");
    takename();
    fscanf(first, "%d%d", &number,&node_number);
    fscanf(first, "%d%d",&source,&temp);
    for (int a=1; a<=node_number; a++)
    {
        for (int b=1; b<=node_number; b++)
        {
            if (a == b)
            {
                path_distance[a][b] = 0;
                mask_path[a][b] = 0;
                mask2_path[a][b] = 0;
            }
            else
            {
                path_distance[a][b] = INT_MAX;
                mask_path[a][b] = INT_MAX;
                mask2_path[a][b] = INT_MAX;
            }
        }
    }
    node_time[source] = temp;
    mask_time[source-1] = temp;
    value[source-1] = 1;
    for (int b=1; b<=number; b++)
    {
        fscanf(first,"%d%d%d%d%d",&from,&too,&weight,&time2,&time3);
        store[from].push_back(too);
        store[too].push_back(from);
        node_time[too] = time2;
        mask_time[too-1] = time2;
        value[too-1] = 1;
        path_time[from][too] = time3;
        path_time[too][from] = time3;
        false_time[from-1][too-1] = time3;
        false_time[too-1][from-1] = time3;
        path_distance[from-1][too-1] = weight;
        path_distance[too-1][from-1] = weight;
        mask_path[from -1][too-1] = weight;
        mask_path[too-1][from-1] = weight;
        mask2_path[from -1][too-1] = weight;
        mask2_path[too-1][from-1] = weight;
        matrix[from][too]=weight;
        matrix[too][from]=weight;
    }
    warshall();
    warshall2();
    printf("\n=============== Welcome to The Digital Zoo Management ===============\n\n");
    level1:
    printf("\n\t1. Check All The Animals & Interests\n");
    printf("\t2. Set a Time Consuming Travel Plan\n");
    printf("\t3. Set a Trouble Consuming Travel Plan\n");
    printf("\t4. Set a Full Day Travel Plan\n");
    printf("\t5. Set a Limited Time Travel Plan\n");
    printf("\t6. Find an Specific Location That Your Are looking For\n");
    printf("\t7. Exit\n");
    printf("\nPlease Enter Your Choice: ");
    scanf("%d",&option);

    if (option == 1)
    {
        system("CLS");
        system("COLOR 9");
        getchar();
        for (int a=0; a<node_name.size(); a++)
            cout << a+1 << ": " << node_name[a] << endl;
        system("PAUSE");
        system("CLS");
        system("COLOR 7");
        goto level1;
    }
    else if(option==2)
    {
        system("CLS");
        system("COLOR FD");
        l = 1;
        m = node_number;
        dijkstra(l,path_time);
        pathprint(l,m);
        cout << node_name[l-1];
        while (! namestore[l].empty())
        {
            cout << " -> " << namestore[l].top();
            namestore[l].pop();
        }
        cout<<"\nTotal Time: "<<d[m]+temp<<" Minutes\n\n";
        system("PAUSE");
        system("CLS");
        system("COLOR 7");
        goto level1;
    }

    else if (option == 3)
    {
        system("CLS");
        system("COLOR F0");
        l = 1;
        m = node_number;
        dijkstra(l,matrix);
        pathprint(l,m);
        cout << node_name[l-1];
        while (! namestore[l].empty())
        {
            cout << " -> " << namestore[l].top();
            namestore[l].pop();
        }
        cout<<"\nTotal Distance: "<<d[m]<< " Meter\n\n";
        system("PAUSE");
        system("CLS");
        system("COLOR 7");
        goto level1;
    }

    else if (option == 4)
    {
        system("CLS");
        system("COLOR F2");
        printf("(1)Ostrich ->(2)Peacock ->(3)Flamingo ->(4)Birds Home  ->(5)Penguin ->(6)Macaw ->(7)Gray Parrot ->(8)Mandrill\n");
        printf("->(9)White Headed Capuchin->(10)Monkey ->(11)Baboon ->(12) Ape -> Lion ->(13) Alligator ->(14) Fresh Water Crocodile\n");
        printf("->(15)Salt Water Crocodile->(16)The Royle Bengal Tiger->Leopard ->(17)Wolfe ->(18)Grizzly Bear ->(19)Hayena ->(20)Jaguar\n");
        printf("->(21)King Cobra->(22)Black Mamba->(23)Viper ->(24)Tiger Snake->Anaconda ->(25)Python ->(26)Cemophora ->(27)Rattlesnake\n");
        printf("->(28)Coffee Shop ->(29)Giraffe->(30)Hippopotomus->(31)Zebra ->(32)RhinocerosDeer ->(33)American Bison ->(34)African Buffalo\n");
        printf("->(35)Kangaroo ->(36) Wildebeest ->(37) Elephant->(38)Okapi ->(39)Giant Panda ->(40)Guinea Pig\n");
        system("PAUSE");
        system("CLS");
        system("COLOR 7");
        goto level1;
    }

    else if (option == 5)
    {
        system("CLS");
        system("COLOR F4");
        printf("\nPlease Enter Your Limited Time: ");
        scanf("%d",&limtime);
        limtime /= 2;
        n = node_number*4/sizeof(value[0]);
        knapSack(limtime, mask_time, value, n);
        take11 = n;
        take21 = limtime;
        while (prevee[take11][take21] != 0)
        {
            if (check[take11][take21] == 1)
                namestore[0].push(node_name[take11-1]);
            take21 = prevee[take11][take21];
            take11--;
        }
        cout << node_name[0];
        while (! namestore[0].empty())
        {
            cout << " -> " << namestore[0].top();
            namestore[0].pop();
        }
        printf("\n");
        system("PAUSE");
        system("CLS");
        system("COLOR 7");
        goto level1;
    }

    else if (option == 6)
    {
        system("CLS");
        system("COLOR F9");
        cin.ignore();
        printf("\nPlease Enter Your Nearest Cage Name: ");
        getline(cin, here);
        printf("\nPlease Enter Your Destination Cage Name: ");
        getline(cin, there);
        for (int a=0; a<node_number; a++)
        {
            if (node_name[a] == here)
                temp1 = a;
            else if (node_name[a] == there)
                temp2 = a;
        }
        printf("\nPlease Follow This Path: ");
        cout << node_name[temp1];
        for (int a=storepath[temp1][temp2].size()-1; a>=0; a--)
            cout << " -> " << storepath[temp1][temp2][a];
        cout << "\n";
        system("PAUSE");
        system("CLS");
        system("COLOR 7");
        goto level1;
    }

    else if (option == 7)
    {
        system("CLS");
        system("COLOR FA");
        printf("\n\t||  Thank You ||\n");
        system("PAUSE");
        system("CLS");
       system("COLOR 7");
        return 0;
    }

    else
    {
        system("CLS");
        system("COLOR FC");
        printf("\n\tWrong Input\n");
        system("PAUSE");
        system("CLS");
        system("COLOR 7");
        goto level1;
    }
    return 0;
}
