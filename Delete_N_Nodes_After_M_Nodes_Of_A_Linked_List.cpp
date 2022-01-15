class Solution
{
    
    // https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1
    
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        while(head!=NULL){
            int m=M, n=N;
            while(head!=NULL&&--m)  // traversing m nodes
                head=head->next;
            Node *prev=head;
            while(head!=NULL&&n--)  // skipping n nodes
                head=head->next;
            if(prev!=NULL){
                head=(head!=NULL) ? head->next : NULL;
                prev->next=head;
            }
        }

    }
};
