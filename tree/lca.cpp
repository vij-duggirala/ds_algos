bool v1, v2;

Node *lca_util(Node *root ,int  n1 ,int n2)
{
    if(!root)
        return NULL;
    if(root->data == n1)
      { v1=true;  return root;}
    if(root->data == n2)
        {v2=true; return root; }
    
    Node *l = lca_util(root->left , n1 , n2);
    Node *r = lca_util(root->right , n1 , n2);
    
    if(l && r)    
        return root;
    
    else if(l)
        return l;
    else
        return r;
        
    
}
bool find( Node *root , int key)
{
    if(!root)
        return false;
    
    if(root->data == key)
        return true;
    
    return find(root->left, key) || find( root->right  , key);
}
 
Node* lca(Node* root ,int n1 ,int n2 )
{
   //Your code here
  v1=v2=false;
   Node *temp = lca_util(root , n1 , n2);
   if((v1 && v2) || (v1 && find(temp , n2)) || (v2 && find(temp , n1)))
    return temp;
    return NULL;
}