#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left , *right;
    
    Node(int x)
    {
        data =x;
        left = right = NULL;
    }
};

Node* construct(int A[] , int l , int r , int n)
{
    if(l>r)     
        return NULL;
    if(l==r && l<n)
    {
        Node *root = new Node( A[l]);
        return root;
    }
    
    int m = l +(r-l)/2;
    Node *root = new Node( A[m]);
    root->left = construct(A , l , m-1 ,n);
    root->right = construct( A , m+1 , r ,n);
}
void preorder(Node *root)
{
    if(!root)   
        return;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
	int t;
    int n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int A[n];
	    for(int i=0;i<n;i++)
	        cin>>A[i];
	       
	   Node *root = construct( A ,  0  , n-1 , n);
	   preorder(root);
	   cout<<"\n";
	}
	
	return 0;
}