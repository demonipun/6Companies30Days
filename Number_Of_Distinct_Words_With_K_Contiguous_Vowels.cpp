class Solution
{
  public:
    
    // https://practice.geeksforgeeks.org/problems/7b9d245852bd8caf8a27d6d3961429f0a2b245f1/1/
  
    int kvowelwords(int n, int k) {
        vector<vector<long long>> dp(n+1, vector<long long>(k+1));
        // dp[i][j] = number of words of length i and having at most j continuous vowels
        long long MOD=1e9+7;
        for(int j=0;j<=k;j++) // i=0
            dp[0][j]=1; // to facilitate multiplication -> not true practical situation
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                if(j==0)
                    dp[i][0]=(dp[i-1][k]*21)%MOD; // no vowels in length i
                else
                    dp[i][j]=((dp[i-1][k]*21)%MOD+(dp[i-1][j-1]*5)%MOD)%MOD;
                // dp[i-1][k] -> last term in i-1 length
            }
        }
        return (int)dp[n][k];
    }
};
