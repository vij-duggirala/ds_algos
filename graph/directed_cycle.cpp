#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *adj;

    public:
        Graph(int V)
        {
            this->V = V;
            adj = new list<int>[V];
        }

        void addEdge(int u , int v)
        {
            adj[u].push_back(v);
        }

        bool util(int start , vector<int> &flag)
        {
            if(flag[start] == -1)
            {
                flag[start] = 0;

                for(auto it = adj[start].begin(); it!=adj[start].end(); it++)
                    if(flag[*it] == 0)
                        return true;
                    else if(flag[*it] == -1 && util(*it , flag))
                        return true;
            }
            flag[start] = 1;
            return false;

        }

        bool isCyclic()
        {
            int i;
            vector<int> flag;
            flag.resize(V);
            for(i=0;i<V;i++)
                flag[i] = -1;
            
            for(i=0;i<V;i++)    
                if(flag[i] == -1)
                    if(util(i , flag))
                        return true;
        
            return false;

        }

};

int main()
{
        Graph G(4);
        G.addEdge(0, 1);
        G.addEdge(1,2);
        G.addEdge(2 , 3);

        if(G.isCyclic())    
            cout<<"Found";
        else
            cout<<"NO";


}