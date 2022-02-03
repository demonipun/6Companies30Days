class Solution{
    public:

    // https://practice.geeksforgeeks.org/problems/express-as-sum-of-power-of-natural-numbers5647/1
    
    int find(vector<vector<long long>>& dp, int n, int x, int i, int p)
    {
        if(n==0)
            return 1;
        if(i>n)
            return 0;
        if(dp[n][i]!=-1)  // Memorization
            return dp[n][i]%p;
        int z=pow(i,x);
        if(z<=n) {
            dp[n][i]=find(dp, n-z, x, i+1, p)+find(dp, n, x, i+1, p);
            // Result = number of possible ways using z + number of possible ways without using z
            return dp[n][i]%p;
        }
        return dp[n][i]=0; // if z > n
    }
    
    int numOfWays(int n, int x)
    {
        vector<vector<long long>> dp(n+1, vector<long long> (n+1, -1)); // 1 <= n <= 1000
        int mod=1e9+7;
        return find(dp, n, x, 1, mod);
    }
    
    /*
    ----------    Iterative    ----------
    int numOfWays(int n, int x)
    {
        // dp[i] represents number of ways to represent i
        vector<long long> dp(n+1, 0);
        
        // Always 1 way to represent 0 or 1
        // as sum of powers of natural numbers
        dp[0] = dp[1] = 1;
        int mod=1e9+7;
        // For n == 10 and x == 2, we will only try till 3^2
        // else, the sum will exceed n
        int maxLimit = pow(n, 1.0/x);

        for(int i = 2; i <= maxLimit; i++){
            int curr = pow(i, x);
            // Same as "include" condition in recursive code
            // and since, we are running a loop from i to maxLimit
            // the "exclude" condition is also handled.
            for(int j = n; j >= curr; j--){
                dp[j] += (dp[j-curr]%mod);
            }
        }
        
        return dp[n]%mod;
    }
    */
};
