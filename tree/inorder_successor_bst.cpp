Node *gm( Node * temp)
{
    while(temp->left)
        temp = temp->left;
    return temp;
}

Node * inOrderSuccessor(Node *root, Node *x)
{
    //Your code here
    if(x->right)
        return gm(x->right);
    
    Node *succ = NULL;
    
    while(root)
    {
        
        if(x->data < root->data)
        {
            succ = root; 
            root= root->left;
        }
        else if( x->data > root->data)
            root = root->right;
        else
            break;
    }
    return succ;
    
}