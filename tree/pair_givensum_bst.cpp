vector<int> res;
void inorder(Node *root)
{
    if(!root)   
        return;
    
    inorder(root->left);
    res.push_back(root->data);
    inorder(root->right);
}
bool isPairPresent(struct Node *root, int target)
{
    res.clear();
    inorder(root);
    
    int i , j;
    i=0; j = res.size()-1;
    while(i<j)
    {
        if(res[i] + res[j] == target)
            return true;
        
        else if ( res[i] + res[j] < target)
            i++;
        else
            j--;
    }
    return false;
}