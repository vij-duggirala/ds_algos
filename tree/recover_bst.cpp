void util ( Node *root , Node** prev , Node **f , Node **m , Node **l)
{
    if(root)
    {
        util(root->left , prev , f, m ,l);
        
        if(*prev && root->data < (*prev)->data)
        {  if(!(*f))
            {
            *f = *prev; *m = root;
            }
            else
                *l = root;
        }
        *prev = root;
        
        util(root->right , prev , f, m , l);
    }
}



struct Node *correctBST( struct Node* root )
{
    Node *prev , *f , *m , *l;
    prev = f = m = l = NULL;
    util( root , &prev , &f, &m , &l);
    
    if(f && l)
        swap(&(f->data) , &(l->data));
    else if(f && m)
        swap(&(f->data) ,  &(m->data));
    
    return root;
    
}
