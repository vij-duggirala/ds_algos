#include<bits/stdc++.h>
using namespace std;



class Graph
{
    int V;
    list <int> *adj;
    bool isCyclicUtil( int v, bool visited[] , int parent);

    public:
        Graph(int V)
        {
            this->V = V;
            adj = new list <int>[V];
        }

        void addEdge(int v , int w)
        {
            adj[v].push_back(w);
            adj[w].push_back(v);
        }

        bool isCyclic();
};

bool Graph::isCyclicUtil(int v , bool visited[], int parent)
{
    visited[v]= true;

    for(auto it = adj[v].begin(); it!=adj[v].end(); it++)
    {
        if(!visited[*it])
        {
            if(isCyclicUtil(*it , visited , v))
                return true;
        }

        else if( *it!= parent)
            return true;
    }

    return false;
}


bool Graph::isCyclic()
{
    bool *visited = new bool[V];
    for(int i =0 ; i<V;i++)
        visited[i] = false;
    
    for(int u = 0; u < V; u++)
        if(!visited[u])
            if(isCyclicUtil(u , visited, -1))
                return true;

    return false;

}


int main()
{
    int n , k, a, b, i;
    cin>>n>>k;

    Graph g(n);
    for(i=0;i<k;i++)
    {
        cin>>a;
        cin>>b;
        g.addEdge(a, b);
    }

    if(g.isCyclic())
        cout<<"Graph contains cycle";
    else    
        cout<<"Graph does not contain cycle";
    
    cout<<"\n";
}