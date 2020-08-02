
#include<bits/stdc++.h>
using namespace std;
class graph
{
    int V;
    list<int> *adjList;
public:
    graph(int v){
    V=v;
    adjList = new list<int>[V];
    }
    void addEdge(int u, int v, bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void printGraph()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i<<"->";
            for(int node: adjList[i])
            {
                cout<<node<<", ";
            }
            cout<<endl;
        }
    }
    void bfs(int src, int dest)
    {
        bool *visited = new bool[V+1]{0};
        int *dist = new int[V+1]{0};
        int *parent = new int[V+1];
        memset(parent, -1, sizeof(parent));
        queue<int> q;
        q.push(src);
        visited[src]=true;
        //cout<<"BFS: ";
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            //cout<<node<<" ";
            for(int neighbour: adjList[node])
            {
                 if(visited[neighbour]==false)
                 {
                     q.push(neighbour);
                     visited[neighbour]=true;
                     dist[neighbour]= 1 + dist[node];
                     parent[neighbour] = node;
                 }
            }
        }
        cout<<"\nShortest path to reach the destination node "<<dest<<" is: ";
        int temp=dest;
        while(temp!=-1)
        {
            cout<<temp<<"<--";
            temp=parent[temp];
        }
    }
};
int main()
{
    int board[50]={0};

    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=-10;
    board[32]=-2;
    board[34]=-22;
    graph g(50);

    //Insert edges
    for(int i=0;i<36;i++)
    {
        //Throw a dice from 1 to 6
        for(int dice=1;dice<=6;dice++)
        {
            int v = i + dice + board[i+dice];
            g.addEdge(i,v,false);
        }
    }

    //Shortest path
    g.bfs(0,36);

    return 0;
}


