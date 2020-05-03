int maxi;
void util (Node *root , int lvl )
{
    if(!root)
        return;
    if(lvl > maxi)
    {
        cout<<root->data<<" ";
        maxi = lvl;
    }
    util(root->left , lvl+1);
    util(root->right , lvl+1);
    
}

void leftView(Node *root)
{
    maxi = 0;
   util ( root , 1);
   
}