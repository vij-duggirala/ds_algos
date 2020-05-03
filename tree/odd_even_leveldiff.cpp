int getLevelDiff(Node *root)
{
    stack <Node *> p  ,q;
    int l , r;
    l=r=0;
    
    q.push(root);
    int dd = 1;
    while(!q.empty())
    {
        Node *temp = q.top();
        q.pop();
        if(temp->left)
            p.push(temp->left);
        if(temp->right)
            p.push(temp->right);
        
       
        if(dd%2)
            l += temp->data;
        else
            r += temp->data;
        
       
        if(q.empty())
        {
            dd++;
            swap(q , p);
        }
    }
    
    return (l-r);
   
}
