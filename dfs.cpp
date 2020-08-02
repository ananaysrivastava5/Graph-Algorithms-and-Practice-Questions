#include<bits/stdc++.h>
using namespace std;
class graph
{
    int V;
    list<int> *adjList;
public:
    graph(int v)
    {
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
    void dfs_util(int src, bool visited[])
    {
        visited[src]=true;
        cout<<src<<" ";
        for(auto neighbours: adjList[src])
        {
            if(visited[neighbours]==false)
            {
                dfs_util(neighbours, visited);
            }
        }
    }
    void dfs(int src)
    {
        bool *visited = new bool[V+1]{0};
        cout<<"DFS: ";
        dfs_util(src, visited);
    }
};
int main()
{
    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.dfs(2);
    return 0;
}
