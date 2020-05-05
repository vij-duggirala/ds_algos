int search( vector<int> inorder ,int l , int r, int tar)
    {
        for(int i=l;i<=r; i++)
                if(inorder[i] == tar)
                        return i;
    
        return -1;
        
    }
Node* buildTree(int inorder[],int preorder[], int l, int r)
{
//add code here.
static int p=0;
        if(r<l)
            return NULL;
        
        Node *root = new Node(preorder[p]);
        
        int k = search(inorder ,l , r, preorder[p]);
        p++;
        
        if(l==r)
            return root;
        
        root->left = build(  l , k-1  , preorder , inorder );
        root->right = build( k+1 , r ,preorder , inorder );
        
        return root;
}