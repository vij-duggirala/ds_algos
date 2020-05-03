Node * util ( Node *root , int n1 , int n2)
{
    if(!root)
        return NULL;
    if( n1 == root->data || n2 == root->data)
        return root;
    
    
    if( n1< root->data && n2<root->data )
        return util ( root->left , n1 , n2);
    if( n1>root->data && n2>root->data)
        return util( root->right, n1 , n2);
    
    return root;
}

bool find( Node *root , int key)
{
    if(!root)
        return false;
    if(root->data == key)
        return true;
    return find(root->left, key)||find(root->right , key);
}

Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   
   Node *temp = util(root , n1 , n2);
   if(find(root , n1) && find(root , n2))
    return temp;
    return NULL;
    
}
