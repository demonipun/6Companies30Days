class Solution
{
    public:
    
    // https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1/
    
    //Function to connect nodes at same level.
    void connect(Node* root)
    {
        // Using BFS for Level-Order Traversal
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
           int sz=q.size();
           while(sz--){
                Node* temp=q.front();
                q.pop();
                if(sz!=0)
                   temp->nextRight=q.front();
                else
                    temp->nextRight=NULL;
                if(temp->left!=NULL)
                   q.push(temp->left);
                if(temp->right!=NULL)
                   q.push(temp->right);
           }
       }
    }    
      
};
