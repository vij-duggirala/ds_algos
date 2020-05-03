void reversePrint(Node *root)
{
    //Your code here

    queue<Node*> q ;
    stack<int> p;
    q.push(root);
    
    while(!q.empty())
    {
        Node* temp = q.front(); q.pop();
        p.push( temp->data);
        
         if(temp->right)
            q.push(temp->right);
        if(temp->left)
            q.push(temp->left);
     
    }
    
    while(!p.empty())
    {
        cout<<p.top()<<" ";
        p.pop();
    }

}