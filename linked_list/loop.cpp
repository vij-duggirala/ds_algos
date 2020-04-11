

bool has_loop(Node *head)
{
    Node *slow, *fast;
    slow = fast = head;

    while(fast && fast->next!=NULL)
    {
        fast = fast->next->next;
        if(fast==slow)
            return true;
        else
            slow=slow->next;
    }

    return false;   
}


//remove loop / print start of loop

void remove_loop(Node* head)
{
    Node *fast, *slow;
    fast = slow = head;
    int flag = 0;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast=fast->next->next;
        if(slow==fast)
            {flag = 1; break;} 
    }

    if(flag==1)
    {
        slow= head;
        while(slow->next!=fast->next)
        {
            slow = slow->next;
            fast=fast->next;
        }
        //data at the start of the loop
        cout<<fast->next->data;
        fast->next=NULL;
    }

}