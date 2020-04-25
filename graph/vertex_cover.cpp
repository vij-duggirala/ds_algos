#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

    public:
        Graph(int V)
        {
            this->V = V;
            adj = new list<int>[V];
        }

        void addEdge(int a , int b)
        {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        void vertexCover()
        {
            bool visited[V];
            memset(visited, false, V);

            for(int u = 0;u<V;u++)
            {
                if(visited[u]==false)
                {
                    for(auto it = adj[u].begin(); it!=adj[u].end();it++)
                        if(visited[*it] == false)
                        {
                            visited[u] = true;
                            visited[*it] = true;
                            break;
                        }   
                }
            }
            int res = 0;
            cout<<"Vertices in cover: ";
            for(int i=0;i<V;i++)
                if(visited[i])
                {    res++; cout<<i<<" ";}
            cout<<"\nNumber of vertices in vertex cover: "<<res<<"\n";
        }
};

int main()
{
    int v , e  , a , b;
    cin>>v>>e;
    Graph g(v);
    while(e--)
    {
        cin>>a; cin>>b;
        g.addEdge(a, b);
    }
    g.vertexCover();
}