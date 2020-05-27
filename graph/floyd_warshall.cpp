#include <bits/stdc++.h>
using namespace std;
#define INF 1e7

void print_fw(vector<vector<int>> graph , int V)
{
    vector<vector<int>> res(V , vector<int>( V , INF ));
    int i , j , k;
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
            res[i][j]= graph[i][j];
    for(k=0;k<V;k++)
    {
        for(i=0;i<V;i++)
            for(j=0;j<V;j++)
                if(res[i][k] != INF && res[k][j] !=INF && (res[i][k] + res[k][j]) < res[i][j])
                    res[i][j] = res[i][k] + res[k][j];
    }
    
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
            if(res[i][j]== INF)
                cout<<"INF ";
            else
                cout<<res[i][j]<<" ";
        cout<<"\n";
    }
    
    
}

int main() {
    int t , V , i , j;
    cin>>t;
    while(t--)
    {
        cin>>V;
        vector<vector<int>> graph(V  , vector<int>(V, INF));
        for(i=0;i<V;i++)
            for(j=0;j<V;j++)
                cin>>graph[i][j];
            
        print_fw(graph , V);
        
    }
    
}