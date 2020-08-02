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
    bool dfs_util(int src, bool visited[], bool recStack[])
    {
        if(visited[src]==false)
        {
            visited[src]=true;
            recStack[src]=true;
        }
        //cout<<src<<" ";
        for(auto neighbours: adjList[src])
        {
            if(visited[neighbours]==false && dfs_util(neighbours, visited, recStack))
            {
                return true;
            }
            else if(recStack[neighbours]==true)
                return true;
        }
        recStack[src]=false;
        return false;
    }
    bool isCyclic()
    {
        bool *visited = new bool[V+1]{0};
        bool *recStack = new bool[V+1]{0};
        for(int i=0;i<V;i++)
        {
            if(dfs_util(i, visited, recStack))
                return true;
        }
        return false;
    }
};
int main()
{
    graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    if(g.isCyclic())
        cout<<"Graph contains cycle";
    else
        cout<<"Graph doesn't contain cycle";
    return 0;
}

