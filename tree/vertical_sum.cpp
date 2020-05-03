map<int , int> res;

void util( Node *root , int b)
{
    if(!root)
        return;

    res[b] += root->data;
    util(root->left , b-1);
    util(root->right, b+1);
    
}


void verticalSum(Node *root) {
    // add code here.
    res.clear();
    util( root  , 0);
    
    for(auto it=res.begin(); it!=res.end(); it++)
        cout<<it->second<<" ";
    
}