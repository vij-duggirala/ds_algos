bool util ( Node *a , Node * b)
{
    if(!a && !b)
        return true;
    if(!a || !b)
        return false;
    
    return util( a->left, b->right) && util( a->right , b->left);
}

bool IsFoldable(Node* root)
{
    return util ( root , root);
}