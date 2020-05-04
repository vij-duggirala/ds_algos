vector<int> res;
void inorder(Node *root , int k)
{
    if(root && res.size() < k)
    {
        inorder(root->left , k);
        res.push_back(root->data);
        inorder(root->right , k);
    }
    
}

int KthSmallestElement(Node *root, int k)
{
    res.clear();
    inorder(root , k);
    if(res.size()>=k)
        return res[k-1];
    
    return -1;
}