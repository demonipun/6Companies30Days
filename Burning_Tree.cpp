class Solution {
  public:
    
    // https://practice.geeksforgeeks.org/problems/burning-tree/1/
  
    int minTime(Node* root, int target) 
    {
        // We have parent-child mapping ( parent->left AND parent->right )
        // As when the node burns, the next time unit node's children and node's parents also burn
        // So, we need to have Child-parent mapping as well 
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        q.push(root);
        Node* burnt;
        while(!q.empty()) {
            Node* node=q.front();
            q.pop();
            if(node->data==target)
                burnt=node;
            if(node->left!=NULL) {
                mp[node->left]=node; // Child-parent mapping
                q.push(node->left);
            }
            if(node->right!=NULL) {
                mp[node->right]=node; // Child-parent mapping
                q.push(node->right);
            }
        }
        // Stimulate the BURNING OF THE TREE now
        int ans=0; 
        q.push(burnt);  // Burnt node is pushed into the queue which is initially empty
        unordered_map<Node*, bool> vis; // Keep track o the nodes we visited
        vis[burnt]=true;
        while(!q.empty()) {
            int n=q.size();
            bool flag=false;
            while(n--) {
                Node* node=q.front();
                q.pop(); 
                if(mp[node]!=NULL && !vis[mp[node]]) {
                    vis[mp[node]]=true;
                    q.push(mp[node]);
                    flag=true;
                }
                if(node->left!=NULL && !vis[node->left]) {
                    vis[node->left]=true;
                    q.push(node->left);
                    flag=true;
                }
                if(node->right!=NULL && !vis[node->right]) {
                    vis[node->right]=true;
                    q.push(node->right);
                    flag=true;
                }
            }
            if(flag)   // Atleast one Node has been burnt in the current time
                ans++;
        }
        return ans;
    }
};
