#include<bits/stdc++.h>
using namespace std;


int recursiveks(int weight[] , int price[] , int W , int n)
{
    if(W==0 || n==0)
        return 0;
    else if(weight[n-1]<=W)
            return max (price[n-1] +recursiveks(weight, price, W-weight[n-1], n-1) , recursiveks(weight, price, W, n-1));
    else
            return recursiveks(weight, price, W, n-1);


}


int main()
{
    int n, W, i, w;
    cout<<"Enter number of items:\n";
    cin>>n;
    cout<<"Enter max. weight:\n";
    cin>>W;

    int weight[n] , price[n];
    cout<<"Price- Weight\n";
    for(i=0;i<n;i++)    
    {
        cin>>price[i]; 
        cin>>weight[i];
    }

    cout<<"\n"<<recursiveks(weight, price, W, n)<<"\n\n";
    int ks[n+1][W+1];

    for(i=0;i<=n;i++)
    {
        for(w=0;w<=W;w++)
        {
            if(w==0 || i==0 )
                ks[i][w]=0;
            
            else if(weight[i-1] <= w)
                ks[i][w] = max(price[i-1]+ ks[i-1][w-weight[i-1]] , ks[i-1][w]);
            else
                ks[i][w] = ks[i-1][w];
            
            cout<<ks[i][w]<<" ";
        }
        cout<<"\n";
    }




    vector<pair<int, int>> el;
    int res= ks[n][W];
    cout<<ks[n][W]<<"\n";
    w=W;
    for(i=n; i>0 && res >0; i--)
    {
        
        if(res== ks[i-1][w])
            continue;
        else
        {
            el.push_back(make_pair(price[i-1] , weight[i-1]));
            res = res - price[i-1];
            w= w- weight[i-1];
        }
    }

    for(auto it=el.begin();it!=el.end(); it++)
        cout<<it->first<<" "<<it->second<<"\n";




}