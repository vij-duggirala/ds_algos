struct TreeNode
{
    int val;
    TreeNode *left , *right;
};
vector<int> postorderTraversal(TreeNode* root) {
         stack<TreeNode*> s;
        vector<int> res;
        if(!root)   
            return res;
        s.push(root);
        
        TreeNode *temp;
        while(!s.empty())
        {
            res.push_back(s.top()->val);
            temp = s.top();        
            s.pop();
            if(temp->left)
                s.push(temp->left);
            if(temp->right)
                    s.push(temp->right);
        }
        
        reverse(res.begin() ,res.end());
        return res;
        
        
    }