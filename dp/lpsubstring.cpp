#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    cin>>a;
    int n = a.length();

    int i , j , k, maxim ,start;
    int dp[n][n];

    maxim =1;
    start =0;

    for(i=0;i<n;i++)
        dp[i][i]=1;

    for(i=0;i<n-1;i++)
        if(a[i] == a[i+1])
            {dp[i][i+1] = 1; maxim=2; start=i; } 
        else
            dp[i][i+1] = 0;
        
   
    for(k=3;k<=n;k++)
        for(i=0; i<n;i++)
        {
            j= i+k-1;
            if(dp[i+1][j-1] ==1 && a[i]==a[j])
            {    dp[i][j] = 1;
                 if(k>maxim)
                {
                    maxim = k; start = i;
                }
            }
        }

    
    cout<<maxim<<"\n";
    for(i=start; i<start+maxim; i++)    
        cout<<a[i];



}