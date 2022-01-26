class Solution {
  public:
    
    // https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1/
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    
    int dfs(Node *node) {
        if(node==NULL) // Leaf k liye yahan par return hoga
            return 0;
        int temp=node->data;
        node->data=dfs(node->left)+dfs(node->right);
        return node->data+temp; // Non - Leaf k liye return value
    }
    
    void toSumTree(Node *node)
    {
        dfs(node);
    }
};
