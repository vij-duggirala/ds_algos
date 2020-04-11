#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , m ,X , x, k , i , j;
    cout<<"Enter number of dices: ";
    cin>>n;

    cout<<"Enter number of sides: ";
    cin>>m;

    cout<<"Enter total required: ";
    cin>>X;

    int dp[n+1][X+1];

    for(i=0;i<=X ;i++)
        dp[0][i] =0;
    
    for(i=1;i<=m && i<=X; i++)  
        dp[1][i] =1 ;
    
    for(i=0;i<=n;i++)
        dp[i][0] =0;

    
    for(i=2;i<=n;i++)
        for(j=1;j<=X;j++)
        { 
            dp[i][j] = 0;
            for(k=1; k<=m && k<=j; k++)
                dp[i][j]+= dp[i-1][j-k];
            
        }

    cout<<dp[n][X];    


}