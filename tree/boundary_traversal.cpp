
void leftt( Node *root)
{
    if(!root)
        return;
    
    if(root->left)
    {
        cout<<root->data<<" ";
        leftt(root->left);
    }
    else if ( root->right)
    {
        cout<<root->data<<" ";
        leftt(root->right);
    }
}

void leavess(Node *root)
{
    if(!root)
        return;
    
    leavess(root->left);
    leavess(root->right);
    
    if(!root->left && !root->right)
        cout<<root->data<<" ";
}

void rightt(Node *root)
{
    if(!root)
        return;
    if(root->right)
    {
        rightt(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left)
    {
        rightt(root->left);
        cout<<root->data<<" ";
    }
    
}



void printBoundary(Node *root)
{
    
     if(!root)  
        return;
    
    cout<<root->data<<" ";
    
    leftt(root->left);
    leavess(root->left);
    leavess(root->right);
    rightt(root->right);
}