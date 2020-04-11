int findNode(int d, SinglyLinkedListNode* longer , SinglyLinkedListNode* smaller)
{
    int cnt = 0;
    while(cnt!=d)
    {   
        longer = longer->next;
        cnt++;
    }
    while(longer!=NULL && smaller!=NULL)
    {   
        if(longer==smaller)
            return longer->data;
        longer = longer->next;
        smaller= smaller->next;
    }
    return -1;
}

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
        SinglyLinkedListNode *temp1 = head1;
        SinglyLinkedListNode *temp2 = head2;

        int cnt1 , cnt2;
        cnt1=cnt2=0;

        while(temp1!=NULL)
        {
            cnt1++;
            temp1 = temp1->next;
        }

        while(temp2!=NULL)
        {
            cnt2++;
            temp2= temp2->next;
        }

        if(cnt1 >cnt2)
            return findNode( cnt1-cnt2 , head1, head2);
        else
            return findNode( cnt2 - cnt1 , head2 , head1);


}









//if it is guaranteed that a merge node exists, them:

int findMergeNode( SinglyLinkedListNode *head1 , SinglyLinkedListNode* head2)
{
    SinglyLinkedListNode *temp1 , *temp2;
    temp1 = head1; temp2 = head2;

    
    while(temp1!=temp2)
    {
        if(temp1->next)
            temp1=temp1->next;
        else
            temp1= head2;
        

        if(temp2->next)
            temp2=temp2->next;
        else
            temp2 = head1;
    }
    return temp1->data;

}