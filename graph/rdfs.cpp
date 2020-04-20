#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

    void DFSUtil( int v , bool visited[])
    {
        visited[v] = true;
        cout<<v<<" ";

        for(auto it = adj[v].begin(); it!=adj[v].end(); it++)  
            if(!visited[*it])
                DFSUtil(*it, visited);

    }

    public:
        Graph(int V)
        {
            this->V = V;
            adj = new list<int>[V];
        }

        void addEdge(int u , int  v)
        {
            adj[u].push_back(v);

        }

        void rDFS(int s)
        {
            bool *visited = new bool[V];
            int i;
            for( i =0;i<V; i++) 
                visited[i]=  false;
            
            DFSUtil(s , visited);
            for(i=0;i<V;i++)
                if(!visited[i])
                    DFSUtil(i , visited);
        }


};

int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 

    g.rDFS(0);
  
    return 0; 
} 