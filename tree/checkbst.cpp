int util( Node *root)
{
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return root->data;
    
    return root->data + util(root->left) + util(root->right);
}

bool isSumTree(Node* root)
{
    if(!root)
        return true;
    if(!root->left && !root->right)
        return true;
    if(util(root->left)+util(root->right)!=root->data)
        return false;
    return (isSumTree(root->left) && isSumTree(root->right));
    
}