class Solution {
public:
    
    // https://leetcode.com/problems/guess-number-higher-or-lower-ii/
    
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // dp[i][j]=min amount of money needed to guarantee a win searching within i and j
        // dp[i][j]=min of (pivot+max(dp[i][pivot], dp[pivot+1][j])) for pivot between start and end
        for(int len=1; len<=n; len++) { 
            for(int start=1; start+len<=n; start++) {
                int end=start+len;
                int cost=1e9; // Let the intial cost to guarantee a win be Infinity(1e9)
                for(int pivot=start; pivot<end; pivot++) 
                    cost=min(cost, pivot+max(dp[start][pivot-1], dp[pivot+1][end]));
                dp[start][end]=cost;
            }
        }
        return dp[1][n];
    }
};
