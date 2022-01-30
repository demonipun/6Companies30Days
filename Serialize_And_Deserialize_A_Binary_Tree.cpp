class Solution
{
    public:
    
    // https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1
    
    void preOrder(Node* node, vector<int>& ans) {
        if(node==NULL) {
            ans.push_back(-1); // NULL => -1
            return;
        }
        ans.push_back(node->data);
        preOrder(node->left, ans);
        preOrder(node->right, ans);
    }
    
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        vector<int> ans;
        preOrder(root, ans);
        return ans;
    }
    
    int idx=0; // index of the array
    //Function to deserialize a list and construct the tree.
    Node* deSerialize(vector<int> &A)
    {
        if(idx==A.size()||A[idx]==-1) {
            idx++; 
            return NULL; 
        }
        Node* root=new Node(A[idx]);
        idx++;
        root->left=deSerialize(A);
        root->right=deSerialize(A);
        return root;
    }
};
