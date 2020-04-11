#include<bits/stdc++.h>
using namespace std;
int min(int a , int b)
{
    return a<b?a:b;
}
int main()
{
    int n, i ,j , k , l ;
    string str;
    cin>>str;

    n = str.length();

    int pal[n][n];

    for(i=0;i<n;i++)
        pal[i][i] = 1;
    
    for(i=0;i<n-1;i++)
        if(str[i] == str[i+1])
            pal[i][i+1] = 1;
        else
            pal[i][i+1] = 0;
        

    for(k=3;k<=n;k++)
        for(i=0;i<n;i++)
        {
            j= i+k-1;
            if(str[i] == str[j] && pal[i+1][j-1])
                pal[i][j] = 1;
            else
                pal[i][j] = 0;
        }

    int cuts[n];
    cuts[0]  =0;

    vector<int> res;
    for(i=1;i<n;i++)
        if(pal[0][i])
            cuts[i] = 0;
        else
        {
                k=-1;
                cuts[i] = INT_MAX;
                for(j=0;j<i;j++)
                    if(pal[j+1][i])
                        if(cuts[j] + 1 < cuts[i])  
                        {    cuts[i] = cuts[j]+1; k = j;}
              

        }



    cout<<cuts[n-1]<<"\n";
    
   
}