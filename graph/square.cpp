
#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b)
{
    return a > b;
}


int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> graph[n];
    vector<int> sq_graph[n];
    int visited[n][n];
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);

        sq_graph[a].push_back(b);
        sq_graph[b].push_back(a);
        visited[a][b] = 1;
        visited[b][a] = 1;
    }
      for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            int u = graph[i][j];
            for (int k = 0; k < graph[u].size(); k++)
            {
                int v = graph[u][k];
                if (v == i)
                    continue;
                if (!visited[i][v])
                {
                    visited[i][v] = 1;
                    visited[v][i] = 1;

                    sq_graph[i].push_back(v);
                    sq_graph[v].push_back(i);
                }
            }
        }
    }
    cout << "Edges in SQUARE graph are : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < sq_graph[i].size(); j++)
        {
            int u = sq_graph[i][j];
            if (visited[i][u] != 2)
            {
                visited[i][u] = 2;
                visited[u][i] = 2;
                cout << i << " - " << u<<"\n";
            }
        }
        cout <<"\n";
    }
}
