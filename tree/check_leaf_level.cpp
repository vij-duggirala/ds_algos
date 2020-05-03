int l;
bool util(Node *root , int lvl)
{
    if(!root)
        return true;
    if(!root->left && !root->right)
    {
        if(l==-1)   
            l=lvl;
        else
        {
            if(l!=lvl)
                return false;
        }
    }    
        
    return util(root->left, lvl+1) && util(root->right, lvl+1);
        
        
}


bool check(Node *root)
{
    //Your code here
    l=-1;
    return util(root , 0);
    
}