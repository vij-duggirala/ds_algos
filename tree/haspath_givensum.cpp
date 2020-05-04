bool hasPathSum(Node *node, int sum) {
    // Your code here
    if(!node)
        return sum==0;
        
    sum = sum-node->data;
    if(sum==0 && !node->left && !node->right)
        return true;
    bool ans = false;
    if(node->left)
        ans= ans || hasPathSum(node->left , sum);
    
    if(node->right)
        ans = ans|| hasPathSum(node->right , sum);
    
    return ans;
}