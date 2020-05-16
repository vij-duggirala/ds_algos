struct Info{
    int size;
    int mini;
    int maxi;
    int ans;
    bool isBST;
};

Info util(Node *root )
{
    if(!root){
        Info curr;
        curr.size = 0;
        curr.mini = INT_MAX;
        curr.maxi = INT_MIN;
        curr.ans = 0;
        curr.isBST = true;
        return curr;
    }
        
    if(!root->left && !root->right)
    {
            Info curr;
        curr.size = 1;
        curr.mini = root->data;
        curr.maxi = root->data;
        curr.ans = 1;
        curr.isBST = true;
        return curr;
    }
    
        
    
    Info l = util(root->left);
    Info r = util(root->right);
    
    Info curr;
    
    if(l.isBST && r.isBST  && (l.maxi < root->data) && (r.mini > root->data))
    {
        curr.size = l.size + r.size +1;
        curr.isBST = true;
        
        curr.mini = min(l.mini , min( root->data , r.mini));
        curr.maxi  = max(l.maxi, max (root->data , r.maxi));
        
        curr.ans = curr.size;
    }
    else
    {
        curr.isBST= false;
        curr.mini = root->data;
        curr.maxi =root->data;
        curr.size = l.size + r.size + 1;
        curr.ans = max( l.ans , r.ans);
    }
    return curr;
    
    
        
    
}

int largestBst(Node *root)
{
    Info res = util(root);	
    return res.ans;
}