void util(Node* root , int lvl  , int k)
{
    if(!root)
        return;
    
    if(lvl == k)    
        cout<<root->data<<" ";
    
    util(root->left , lvl+1 , k);
    util(root->right , lvl+1 , k);
}

void printKdistance(struct Node *root, int k)
{
    util(root , 0 , k);
}