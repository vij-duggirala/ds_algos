#include<bits/stdc++.h>
using namespace std;
int max(int a , int b)
{
    return a>b?a:b;
}


int main()
{
    int n , i , j ;
    cin>>n;
    int Rod[n] , res[n] , index[n];

    for(i=0;i<n;i++)
    {    cin>>Rod[i]; 
        res[i]  = Rod[i];
        index[i] = i;
    }

    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)    
            if(Rod[j] + res[i-j-1]> res[i] )
            {
                    res[i] = Rod[j] + res[i-j-1];
                    index[i] = j;
            }        
    }

    for(i=0;i<n;i++)
        cout<<res[i]<<"\t";
    cout<<"\n";
    for(i=0;i<n;i++)    
        cout<<index[i]<<"\t";
    cout<<"\n";

    i=n-1;
    do
    {
        cout<<index[i]+1<<" ";
        i=i-index[i]-1;
    } while (i>0);
    

    

    cout<<"\n"<<res[n-1];


}