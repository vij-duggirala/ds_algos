TreeNode *util(TreeNode *root , int k , int *sum)
{
    if(!root)
        return NULL;
    
    int lsum = root->val + *sum;
    int rsum = lsum;
    
    root->left = util(root->left , k , &lsum);
    root->right = util(root->right , k , &rsum);
    
    *sum = max(lsum , rsum);
    
    if(*sum < k){free(root);
        root = NULL;}
    return root;


    
}


TreeNode* Solution::solve(TreeNode* A, int B) {
    int sum =0;
    return util(A , B , &sum);
    
    
}

