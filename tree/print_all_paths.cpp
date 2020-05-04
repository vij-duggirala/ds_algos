 vector<int> res;
 void printPath(Node *root)
 {
     if(!root)  
        return;
     if(root->left == root->right)
     {
         res.push_back(root->data);
         for(int i=0;i<res.size(); i++)
            cout<<res[i]<<" ";
        res.pop_back();
        cout<<"#";
        return;
     }
     
     
     if(root->left)
     {
        res.push_back(root->data);
        printPath(root->left);
        res.pop_back();
     }
     if(root->right)
     {
         res.push_back(root->data);
         printPath(root->right);
         res.pop_back();
     }
     
     
     
 }
void printPaths(Node* root)
{
   
    res.clear();
    printPath(root);
    cout<<"\n";
    
    
    
}