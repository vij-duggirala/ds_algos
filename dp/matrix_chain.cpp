#include<bits/stdc++.h>
using namespace std;

void printBracket(int i , int j , int s[][100] ,   char &name)
{
    if(i==j)
    {
            name+=1;
            cout<<name;
            
            return;
    }

    cout<<"(";

    printBracket( i , s[i][j] , s , name);
    printBracket(s[i][j] + 1, j , s , name);
    cout<<")";

}




int main()
{   
    int n , i , j, k , temp, min , L;
    cin>>n;
    int index[n+1];
   
    int dp[n+1][n+1] , s[100][100];

    for(i=0;i<=n;i++)
        cin>>index[i];
    
    for(i=1;i<=n;i++)
    {    dp[i][i] = 0; s[i][i] = 0;}
    
    for(L = 2; L<=n;L++)
    {
        for(i=1;i<=n;i++)
        {
            j = i+L-1;
            if(j<=n){
            dp[i][j] = INT_MAX;
            for(k=i; k<j;k++)  
            {
                temp  = dp[i][k] + dp[k+1][j] + index[i-1]*index[k]*index[j];
                if(temp < dp[i][j])
                {   dp[i][j] = temp; s[i][j] = k;}
            } 
            }
        }
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            if(j>=i)
                cout<<dp[i][j]<<"\t";
            else
                cout<<"\t";
        cout<<"\n";
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            if(j>=i)
                cout<<s[i][j]<<"\t";
            else
                cout<<"\t";
        cout<<"\n";
    }
    char na = 'A';
    printBracket(1 , n ,s , na);
    cout<<dp[1][n];

              



}