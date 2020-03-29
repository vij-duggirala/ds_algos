#include<bits/stdc++.h>
using namespace std;

int maxi(int a , int b)
{
    return a>b?a:b;
}


void lcs(string a , string b, int m , int n )
{
    int dp[m+1][n+1];
    int i,j;
    for(i=0;i<=m;i++)
        dp[i][0]= 0;

    for(i=0;i<=n;i++)
        dp[0][i]=0;
    

    for(i=0;i<m;i++)    
        for(j=0;j<n;j++)
            if(a[i]==b[j])
                dp[i+1][j+1] = 1+ dp[i][j];
            else
                dp[i+1][j+1] = maxi(dp[i][j+1] , dp[i+1][j]);


    for(i=0;i<=m;i++)
        {for(j=0;j<=n;j++)
            cout<<dp[i][j]<<" ";
        cout<<"\n";}



    cout<<"LCS: "<<dp[m][n]<<"\n";
    string res;
    
    j=n; 
    i=m;

    while(i>0 && j>0)
    {   
        //cout<<i<<" "<<j;
        if(a[i] == b[j])
        {       
            //cout<<a[i-1]<<" ";
            res+=a[i-1]; 
             i--; 
             j--; 
        }

        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;

    }
   // cout<<res.size();
    reverse(res.begin(), res.end());
    cout<<res;

}








int main()
{
    string a , b;
    cin>>a;
    cin>>b;
    int m = a.length();
    int n = b.length();

    lcs(a, b,  m , n);
}