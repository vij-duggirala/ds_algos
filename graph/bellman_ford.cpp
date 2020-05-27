#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int s;
    int d;
    int w;
    Edge(int st , int dt , int wt)
    {
        s = st;d = dt;w = wt;
    }
};
class Graph{
    
    int V;int E;
    vector<Edge> edge;
    
    public:
        Graph(int V  , int E){
            this->V  = V;
            this->E = E;
            edge.clear();
            
        }
        
        void ae(int u , int v , int wt)
        {
            Edge e = Edge(u , v ,wt);
            edge.push_back(e);
        }
        
        int bellman_ford()
        {
            int i , cnt , u , v, wt;
            vector<int> dist(V, INT_MAX);
            dist[0] = 0;
            
            for(cnt =0 ; cnt< V; cnt++ )
            {
                
                for(i=0;i<E;i++)
                {
                    u = edge[i].s;
                    v = edge[i].d;
                    wt = edge[i].w;
                    
                    
                    dist[v] = min(dist[u] + wt , dist[v]);
                }
            }

            for(i=0;i<V;i++)
                cout<<dist[i]<<" ";
            cout<<"\n";
            
            for(i=0;i<E;i++)
            {
                u = edge[i].s;
                v = edge[i].d;
                wt = edge[i].w;
                if(dist[v] > dist[u] + wt)
                   { return 1;}
            }
            
            return 0;
        }
};

int main() {
    int t, v, x, y, z , e;
    cin>>t;
    while(t--)
    {
        cin>>v>>e;
        Graph g(v , e);
        while(e--)
        {
            cin>>x>>y>>z;
            g.ae(x, y, z);
        }
        cout<<g.bellman_ford()<<"\n";
    }
	return 0;
}