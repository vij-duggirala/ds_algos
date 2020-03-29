#include<bits/stdc++.h>
using namespace std;
int max(int a , int b)
{
    return a>b?a:b;
}

int min(int a, int b)
{
    return a<b?a:b;
}
struct box{
    int l , b , h;

};

bool comp( const box &a , const box &bb)
{
    return (bb.l*bb.b) < (a.l*a.b);
}


int main()
{
    int n  , i , j , k , l , b ,h;
    cin>>n;
    vector <box> B;

    for(i=0;i<3*n;)
    {
        B.push_back(box());
        cin>>l>>b>>h;
        B[i].l = max( l  , b);
        B[i].b = min(l , b);
        B[i].h = h;

        i++;
        B.push_back(box());
        B[i].h = B[i-1].l;
        B[i].l = max(B[i-1].h , B[i-1].b);
        B[i].b = min(B[i-1].h , B[i-1].b);

        i++;
        B.push_back(box());
        B[i].h = B[i-2].b;
        B[i].l = max(B[i-2].h ,B[i-2].l);
        B[i].b = min(B[i-2].h , B[i-2].l);
        i++;
    }

    sort(B.begin() ,B.end(), comp);
    int msh[3*n];
    
    for(i=0;i<3*n;i++)
    { 
           cout<<B[i].l<<" "<<B[i].b<<" "<<B[i].h<<"\n";
            msh[i] = B[i].h;
    }
    int maxim = msh[0];
    for(i=1;i<3*n; i++)
    {
        for(j=0;j<i;j++)
            if(B[j].l > B[i].l && B[j].b > B[i].b)
              {  msh[i] = max( msh[i] , msh[j]+B[i].h); }
        
        if(msh[i]> maxim)
            maxim = msh[i];
    }
    for(i=0;i<3*n;i++)
        cout<<msh[i]<<" ";
    
    cout<<"\n"<<maxim;

    


}