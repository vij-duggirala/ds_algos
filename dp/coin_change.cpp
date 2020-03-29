#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , m , i , j ;
    cout<<"Enter amount:";
    cin>>n;
    cout<<"Enter the number of denominations: ";
    cin>>m;
    int S[m+1];
    for(i=1;i<=m;i++)
        cin>>S[i];

    int dp[m+1][n+1];

    for(i=0;i<=n; i++)
        dp[0][i] = 0;


    for(i=0;i<=m;i++)
        dp[i][0] = 1;


    for(i=1;i<=m;i++)   
        for(j=1;j<=n;j++)
            if(j >=S[i] )
                dp[i][j] = dp[i-1][j] + dp[i][j-S[i]];
            else
                dp[i][j] = dp[i-1][j];   
    

    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
            cout<<dp[i][j]<<" ";
        cout<<"\n";
    }
    cout<<dp[m][n];
    
    
}