#include<bits/stdc++.h>
using namespace std;
template<typename T>
class graph
{
    map<T, list<T> > adjList;
public:
    graph(){

    }
    void addEdge(T u, T v, bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void printGraph()
    {
        for(auto row: adjList)
        {
            cout<<row.first<<" -> ";
            for(T element: row.second)
            {
                cout<<element<<" , ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    graph<string> g;
    g.addEdge("Amritsar", "Delhi");
    g.addEdge("Amritsar", "Jaipur");
    g.addEdge("Delhi", "Siachen");
    g.addEdge("Delhi", "Bangalore");
    g.addEdge("Delhi", "Agra");
    g.addEdge("Amritsar", "Siachen");
    g.printGraph();
    return 0;
}
