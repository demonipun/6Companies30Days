class Solution {
  public:
    
    // https://practice.geeksforgeeks.org/problems/maximum-profit4657/1
    
    int maxProfit(int k, int n, int a[]) {
        vector<vector<int>> dp(k+1, vector<int>(n,0));
        // dp[i][j] = maximum profit in atmost i transactions using j+1 elements of the array
        for(int i=1;i<=k;i++) {
            int maxi=INT_MIN;
            for(int j=1;j<n;j++) {
                maxi=max(maxi, dp[i-1][j-1]-a[j-1]);
                dp[i][j]=max(dp[i][j-1], maxi+a[j]); // - buying price + selling price
            }
        }
        return dp[k][n-1];
    }
};
