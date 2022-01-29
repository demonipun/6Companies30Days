class Solution {
public:
    
    // https://practice.geeksforgeeks.org/problems/pots-of-gold-game/1/
    
    int solve(vector<int>& nums, vector<vector<int>>& dp, int s, int e)
    {
        if(s>e)
            return dp[s][e]=0;
        if(s==e)
            return dp[s][e]=nums[s];
            
        if(dp[s][e])   // Memorization 
            return dp[s][e];

        int l=nums[s]+min(solve(nums, dp, s+2, e), solve(nums, dp, s+1, e-1));
        // Player 1 takes starting item while Player 2 takes either next item after the starting item or the ending item
        int r=nums[e]+min(solve(nums, dp, s+1, e-1), solve(nums, dp, s, e-2));
        // Player 1 takes ending item while Player 2 takes either the starting item or next item after the ending item

        return dp[s][e]=max(l,r);
    }
   
    int maxCoins(vector<int>&A,int n)
    {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        return solve(A, dp, 0, n-1); // solve( input_array, ans_array, start, end )
    }

    /*
    int maxCoins(vector<int>&A,int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // Since there is j+2 in the dp expression, so we need to precompute for i=0 and i=1
        for(int i=0;i<n;i++)   
            dp[i][i]=A[i];
        for(int i=0;i<n-1;i++)
            dp[i][i+1]=max(A[i], A[i+1]);
            
        for(int i=2;i<n;i++){
            for(int j=0;i+j<n;j++){
                dp[j][i+j]=max(A[j]+min(dp[j+2][i+j], dp[j+1][i+j-1]), A[i+j]+min(dp[j+1][i+j-1], dp[j][i+j-2]));
            }
        }
        
        return dp[0][n-1];
    }
    */
};
