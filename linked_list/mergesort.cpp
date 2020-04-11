Node* sortedMerge(Node* head1,   Node* head2)
{
    Node *res = NULL;
    if(!head1)
        return head2;
    if(!head2)
        return head1;
        
    if(head1->data <= head2->data)
    {   res = head1;
        res->next = sortedMerge(head1->next, head2);
    }
    
    else 
    {
        res = head2;
        res->next = sortedMerge(head1, head2->next);
    }
    
    return res;
}



Node* mergeSort(Node* head) {
    // your code here
    if(!head || !head->next)
        return head;
    
    Node *slow, *fast;
    slow=head;
    fast=head->next;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    fast = slow->next;
    slow->next=NULL;
    Node *a, *b;
    a=mergeSort(head);
    b=mergeSort(fast);
    
    return sortedMerge(a, b);
    
}


