class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        if(n<=2)
            return n;
        // A -> List of sorted integers
        vector<vector<int>> dp(n, vector<int>(10000, 1)); 
        // dp[i][j] = length of AP using j+1 elements from the array with commom difference = j
        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int diff=A[j]-A[i];
                dp[j][diff]=dp[i][diff]+1;
                ans=max(ans, dp[j][diff]);
            }
        }
        return ans;
        /*  Method - 2 (not recommended)
        if(n<=2)
            return n;
        // A -> List of sorted integers
        vector<unordered_map<int,int>> dp(n);
        // dp[i][j] = length of AP using j+1 elements from the array with commom difference = j
        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int diff=A[j]-A[i];
                if(dp[i].find(diff)!=dp[i].end())  // if we do not use find() ---> gives TLE
                    dp[j][diff]=dp[i][diff]+1;
                else
                    dp[j][diff]=2;
                ans=max(ans, dp[j][diff]);
            }
        }
        return ans;
        */
    }
};
