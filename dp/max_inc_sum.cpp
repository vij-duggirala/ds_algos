#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , i , j , max_index;

    cin>>n;
    int A[n];int res[n];
    int count[n];
    for(i=0;i<n;i++)
    {   cin>>A[i];
     count[i] = A[i];  res[i]= i; 
     } 
    
   
    int maxim =count[0] ;
    for(i=1;i<n;i++){
        for(j=0;j<i;j++)
            if(A[i] >=  A[j])
                if(A[i] + count[j] > count[i] )
                {    count[i] = A[i] + count[j]; res[i] = j; }

                

       if(count[i] > maxim)
       { maxim = count[i] ; max_index = i; }
        
    }

    for(i=0;i<n;i++)
        cout<<count[i]<<" ";

    vector <int> seq;
    cout<<"\n"<<maxim;
    i=max_index;
    seq.push_back(A[i]);
    do
    {
        seq.push_back(A[res[i]]);
        i= res[i];

    } while (res[i]!=i);
    
    cout<<"\n";
    for(i=seq.size()-1;i>=0; i--)
        cout<<seq[i]<<"\t";

}