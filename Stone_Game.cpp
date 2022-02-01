class Solution {
public:
    
    // https://leetcode.com/problems/stone-game/
    
    bool stoneGame(vector<int>& piles) {
        /* DP Method
        int n=piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0;i<n;i++) 
            dp[i][i]=piles[i];
        for(int j=1;j<n;j++)
            for(int i=0;i<n-j;i++)
                dp[i][i+j]=max(piles[i]-dp[i+1][i+j], piles[i+j]-dp[i][i+j-1]);
        return dp[0][n-1]>0;
        */
        
        // Thinking Logically
        return true;
    }
};
