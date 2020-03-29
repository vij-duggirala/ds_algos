#include<bits/stdc++.h>
using namespace std;

int mini(int a, int b, int c)
{
    if(a<b)
        if(a<c)
            return a;
        else
            return c;
    else
        if(b<c)
            return b;
        else
            return c;



}


int main()
{
    int r, c, i  , j;
    cin>>r;
    cin>>c;

    int mat[r][c] , s[r][c];
    int max = 0;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
        {
            cin>>mat[i][j];

            if(i==0 || j==0)
                s[i][j] = mat[i][j];
            
            else
            {
                if(mat[i][j]==1)
                    s[i][j]  = 1 + mini(s[i-1][j] , s[i-1][j-1] , s[i][j-1]);
                else
                    s[i][j] = 0;
            }


            if(s[i][j]>max)
                max = s[i][j];

            
        }


   // for(i=0;i<r;i++){
     //   for(j=0;j<c;j++)    
       //     cout<<s[i][j]<<" ";

        //cout<<"\n";
   // }
    
    cout<<max;





}