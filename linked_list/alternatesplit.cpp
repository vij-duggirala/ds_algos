
void alternatingSplitList(struct Node* head) 
{
 Node *temp = head;
 Node *lasta, *lastb;
 if(temp){
  a = new Node(temp->data);
 temp=temp->next;}
 if(temp){
 b=new Node(temp->data);
 temp=temp->next;}
 lasta =a; lastb=b;

 int f =0;
 while(temp)
 {
     if(f%2==0)
     {
         lasta->next =new Node(temp->data);
         temp=temp->next;
         f++;
         lasta = lasta->next;
     }
     else
       {
         lastb ->next=new Node(temp->data);
         temp=temp->next;
         f++;
         lastb = lastb->next;
     }
     
 }
}