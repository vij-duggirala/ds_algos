#include<bits/stdc++.h>
using namespace std;


struct Edge{
    int src, dest , weight;
    Edge(int s , int d , int wt)
    {
        this->src = s;
        this->dest = d;
        this->weight = wt;
    }
};
bool cmp(Edge a , Edge b)
{
    return a.weight<b.weight;
}

class Graph{
    int V;
    vector<Edge> e;
    vector<Edge> res;
    vector<int> subset;
    public:
        Graph(int V)
        {
            this->V = V;
            subset.resize(V);
            for(int i=0;i<V;i++)
                subset[i] = -1;
        }
        void addEdge(int u , int v , int wt)
        {
            e.push_back(Edge(u , v, wt));
        }

        int parent(int a)
        {
            while(subset[a] >=0)
                a = subset[a];
            return a;
        }

        void do_uni(int u , int v)
        {
            u = parent(u);
            v = parent(v);

            if(subset[u] < subset[v])
            {
                subset[u] += subset[v];
                subset[v] = u;
            }
            else
            {
                subset[v] += subset[u];
                subset[u] = v;
            }
        }

        bool ff(int u , int v)
        {
            u = parent(u);
            v  = parent(v);

            return u==v;
        }

        void printkruskal()
        {
            for(int i=0;i<res.size(); i++)
                cout<<res[i].src<<" "<<res[i].dest<<" "<<res[i].weight<<"\n";
        }

        void kruskal()
        {
            sort(e.begin() , e.end() , cmp);    
            int cnt = 0;
            int i =0;
            while(cnt!=V-1 && i < e.size())
            {
                Edge temp = e[i++];
                int u  = temp.src;
                int v = temp.dest;

                if(ff(u , v))
                    continue;
                cnt++;
                do_uni(u , v);
                res.push_back(temp);
            }

            printkruskal();
        }
};

int main()
{
    Graph G(9);
    G.addEdge(7, 6, 1);
    G.addEdge(8 , 2, 2);
    G.addEdge(6, 5, 2);
    G.addEdge(0 , 1 , 4);
    G.addEdge(2, 5, 4);
    G.addEdge(8 , 6, 6);
    G.addEdge(2 , 3, 7);
    G.addEdge(7, 8, 7);
    G.addEdge(0 , 7, 8);
    G.addEdge(1 , 2, 8);
    G.addEdge(3, 4, 9);
    G.addEdge(5, 4, 10);
    G.addEdge(1, 7, 11);
    G.addEdge(3, 5, 14);
    G.kruskal();


}