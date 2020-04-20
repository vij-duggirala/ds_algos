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

        void addEdge(int v, int w)
        {
            adj[v].push_back(w);
        }

        void BFS(int s)
        {
            queue <int> q;
            bool *visited = new bool[V];
            for(int i =0;i < V; i++)
                visited[i] = false;
            visited[s] = true;
            q.push(s);
            int v;
            while(!q.empty())
            {
                v=q.front(); q.pop();
                cout<<v<<" ";

                for(auto it = adj[v].begin(); it!=adj[v].end(); it++)
                    if(!visited[*it])
                        { visited[*it]=true;    q.push(*it); }
            }

        }
};

int main() 
{ 
    int n , k , a, b, i , j;
    cin>>n>>k;
    Graph g(n);

    for(i=0;i<k;i++)
    {
        cin>>a;
        cin>>b;
        g.addEdge(a, b);
    }
    cout<<"\n\nBFS Traversal: ";
    g.BFS(0);
    cout<<"\n";

    return 0; 
} 