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
    void bfs(int src)
    {
        bool *visited = new bool[V+1]{0};
        queue<int> q;
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            cout<<node<<" ";
            for(int neighbour: adjList[node])
            {
                 if(visited[neighbour]==false)
                 {
                     q.push(neighbour);
                     visited[neighbour]=true;
                 }
            }
        }
    }
};
int main()
{
    graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 2);
    g.bfs(0);
    return 0;
}

