vector<bool> vis;
stack<int> s;
    
void dfs( int i , vector<int> adj[] , bool f)
{
    vis[i] = true;
    for(auto it= adj[i].begin(); it!=adj[i].end(); it++)
        if(!vis[*it])
                dfs(*it, adj , f);
    if(f)
    s.push(i);
}

int kosaraju(int V, vector<int> adj[])
{
    while(!s.empty())
        s.pop();
    int i;    
    vector<int> rev[V];
    vis.resize(V);
    for(i=0;i<V;i++)
        vis[i]  = false;
    for(i=0;i<V;i++)
        if(!vis[i])
            dfs(i , adj , true);
    
    for(i=0;i<V;i++)
        for(auto it = adj[i].begin(); it!=adj[i].end(); it++)
            rev[*it].push_back(i);
    
    for(i=0;i<V;i++)
        vis[i] = false;
    int cnt = 0;
    while(!s.empty())
    {
        int temp = s.top(); s.pop();
        if(vis[temp])
            continue;
    
        dfs(temp , rev , false);
        cnt++;
    }
    return cnt;
    

}