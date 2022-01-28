// https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1/
    
int solve(Node* node, int x, int& ans){
    if(node==NULL)
        return 0;
    int l=solve(node->left, x, ans);
    int r=solve(node->right, x, ans);
    if(l+r+node->data==x)
        ans++;
    return l+r+node->data;
}

//Function to count number of subtrees having sum equal to given sum.
int countSubtreesWithSumX(Node* root, int X){
	int ans=0;
	int sum_of_tree=solve(root, X, ans);
	return ans;
}
