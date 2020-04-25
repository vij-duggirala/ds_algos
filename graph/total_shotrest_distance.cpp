#include<bits/stdc++.h>
using namespace std;
#define INF 9999
int graph[1000][1000];

void floydWarshall(int n)
{
    int dist[n][n];
    int i , j , k;
    for(i=0;i<n;i++)    
        for(j=0;j<n;j++)
            dist[i][j] = graph[i][j];
    
    for(k=0;k<n;k++)
    {   
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                    dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
    }

    int sum=0;
    for(i=0;i<n;i++)
        for(j=i;j<n;j++){
        if(dist[i][j] == INF)
            dist[i][j] = -1;
        if(i!=j)
        cout<<i<<" "<<j<<": Cost: "<<dist[i][j]<<"\n";
        sum+=dist[i][j];
        }
        
    cout<<sum<<"\n";
}

int findmin(bool visited[] , int dist[], int n)
{
    int min = INT_MAX;
    int mini = 0;
    for(int i=0;i<n;i++)
        if(!visited[i] && dist[i] < min)
        {
            min = dist[i] ; mini =i;
        }
    return mini;
}
int Total[1000][1000];
void dijkstra(int n , int s)
{
    int i,j;
    int dist[n];    
    bool visited[n];
    for(i=0;i<n;i++)    
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    
    dist[s] = 0;
    for(i=0;i<n-1;i++)
    {
        int u = findmin(visited ,dist, n);
        visited[u] = 1;
    
        for(j =0;j<n;j++)
            if(!visited[j] && graph[u][j] && dist[u]!=INT_MAX)
                dist[j] = min(dist[j] , dist[u]+graph[u][j]);    
    }

    for(i=0;i<n;i++)   
        Total[s][i] = dist[i];
    

    

}

void ini_dijkstra( int n)
{
    
    int i, j;
    for(i=0;i<n;i++)
        dijkstra(n ,i );
    int sum = 0;
    for(i=0;i<n;i++)
        for(j=i;j<n;j++)
            if(j!=i) 
            {
                cout<<i<<" "<<j<<": Cost: "<<Total[i][j]<<"\n";
                sum+=Total[i][j];
            }   
    cout<<"Total: "<<sum<<'\n';
            
    
}


int main()
{
    int n ;
    cin>>n;
    
    for(int i=0;i<n;i++)
        for(int j =0;j<n;j++)
        {    cin>>graph[i][j];
            if(graph[i][j] == -1)
                graph[i][j] = INF;
        }

    cout<<"\nUsing Floyd Warshall Method: \n";
    floydWarshall(n);

    cout<<"\nUsing Dijkstra's method: \n"; 
    ini_dijkstra(n);
}