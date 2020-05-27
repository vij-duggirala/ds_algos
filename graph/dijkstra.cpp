int getmin( vector<int> dist , vector<bool> vis)
{
    int mini , res;
    mini = INT_MAX;
    for(int i=0;i<dist.size();i++)
        if(!vis[i] && dist[i] < mini)
        {
            res  = i; mini =dist[i];
        }
    return res;
    
}

void dijkstra(vector<vector<int>> graph, int src, int V)
{
    vector<int> dist;
    vector<bool> vis;
    vis.resize(V);
    dist.resize(V);
    int i , v , u;
    for(i=0;i<V;i++)
        dist[i] = INT_MAX;
        
    dist[src] = 0;
        
    for(i=0;i<V-1; i++)
    {
        int v = getmin(dist  , vis);
        vis[v] = true;
        for(u =0;u<V;u++)
            if(graph[v][u])
                dist[u] =  min(dist[u] , dist[v] + graph[v][u]);
    }
    for(i=0;i<V;i++)    
    cout<<dist[i]<<" ";
    
}