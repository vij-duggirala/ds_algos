
void printSpiral(Node *root)
{
    
    stack<Node *> f, s;
    if(!root)
        return;
        
    s.push(root);
    int t =1;
    while(!s.empty())
    {
        Node *temp = s.top(); 
        s.pop();
        cout<<temp->data<<" ";
        if(t%2==0)
        {
            if(temp->left)
                f.push(temp->left);
            if(temp->right)
                f.push(temp->right);
        }   
        else
        {
            if(temp->right)
                f.push(temp->right);
            if(temp->left)
                f.push(temp->left);
        }
        if(s.empty())
            { swap(s, f); t++; }
    }
    
}
