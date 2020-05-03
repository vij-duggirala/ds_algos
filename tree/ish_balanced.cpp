int height;
bool util (Node*root , int *height)
{
    int lh , rh ;
    lh = rh =0;
    bool l , r;
    l=r=false;
    if(!root)
    {
        *height = 0;
        return true;
    }
    
    l =util(root->left , &lh);
    r = util(root->right , &rh);

    *height = ((lh>rh)?lh:rh) + 1;
    
    if(abs(lh-rh) >=2)
        return false;
    
    return l&& r;
    
    
}
bool isBalanced(Node *root)
{
       height = 0;
        return util(root , &height);
}