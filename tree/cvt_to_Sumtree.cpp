int util ( Node *root )
{
    if(!root)
        return 0;
    
    int data = root->data;    
    int l = util ( root->left);
    int r= util(root->right);

    root->data = l + r;
    
    return data + l + r;
}
void toSumTree(Node *node)
{
    util ( node);
    return;
}