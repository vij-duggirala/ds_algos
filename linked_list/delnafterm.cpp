void linkdelete(struct Node  *head, int M, int N)
{
    //Add code here   
    Node *temp, *curr;
    curr= head;
    int count;
    while(curr){
    count= 0;
    while(curr && count<M-1)
        {curr=curr->next; count++; }
    if(curr)
    {
        temp = curr->next;
        count = 0;
        while(temp && count< N)
          { count++;  temp=temp->next;}
        curr->next = temp;
        curr=curr->next;
    }
    }
}
