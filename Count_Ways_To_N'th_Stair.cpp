class Solution
{
    public:
    
    // https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1/
    
    // Function to count number of ways to reach the nth stair 
    // when order does not matter.
    long long countWays(int m)
    {
        // When the order does not matter, then for each two steps -> the number of ways increases by 1  
        return m/2+1;
        
        /* Solution when order in which steps are taken matters  : :
        vector<int> dp(m+1, 0);
        dp[1]=1; dp[2]=2;
        for(int i=3;i<=m;i++) 
            dp[i]=dp[i-1]+dp[i-2];
        return dp[m];
        */
    }
};
