#include<bits/stdc++.h>
using namespace std;

int apply( int a, int b , char c)
{
    switch(c)
    {
        case '+': return a+b;
        case '-': return a - b;
        case '*': return a*b;
        case '/': return a/b;
    }
}


int main() {
	int t , i , a, b;
	cin>>t;
	stack <int> s;
	while(t--)
	{
            
        string str;
        cin>>str;
        
        for(i=0;i<str.length();i++)
        {
            if(str[i]>='0' && str[i]<='9')
                s.push(str[i] - '0');
            else 
            {
                a = s.top();s.pop();
                b=s.top(); s.pop();
                s.push( apply( b, a, str[i]));
            }
        }
        cout<<s.top()<<"\n"; s.pop();
	}
	return 0;
}