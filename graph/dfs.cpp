#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list <int> *adj;

    public:
        Graph(int V)
        {
            this->V = V;
            adj = new list<int>[V];
        }

        void addEdge(int a , int b)
        {
            adj[a].push_back(b);
        }

        void iDFS(int start)
        {
            bool *visited = new bool[V];
            for(int i =0; i < V;i++)
                visited[i] = false;
    

            stack <int> s;
            s.push(start);
            int v;
            while(!s.empty())
            {
                v=s.top(); s.pop();
                if(!visited[v])
                {
                    cout<<v<<" ";
                    visited[v] = true;
                }
                for(auto it = adj[v].begin(); it!=adj[v].end(); it++)
                    if(!visited[*it])
                        s.push(*it);
            }       
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
  
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
    g.iDFS(2); 
  
    return 0; 
} 