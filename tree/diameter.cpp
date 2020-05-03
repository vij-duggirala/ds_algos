int util(Node* root ,  int *res )
{
    if(!root)
        return 0;
    int l = util(root->left , res);
    int r = util(root->right , res);
    
    int temp = max(l,r) + 1;
    int ans = max(temp , l+r+1);
    
    *res  = max(*res , ans);
    return temp;
}

int diameter(Node* root) {
    if(!root)
        return 0;
    int res = 0;
    util(root , &res);
    return res;
}
