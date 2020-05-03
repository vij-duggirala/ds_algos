int sum;
void util ( Node *root)
{
    if(!root)
        return;
    util(root->right);
    int temp = sum;
     sum+=root->data; 
    root->data+=temp;
   
    util(root->left);

}
void modify(Node **root)
{

    sum = 0;
    util ( *root );

}