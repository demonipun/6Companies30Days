class Solution {
	public:
	    
	    // https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1
	    
		int CountWays(string s){
		    int n=s.length();
		    long long mod=1e9+7;
		    vector<long long> dp(n+1);
		    dp[n]=1;
		    for(int i=n-1;i>=0;i--) {
		        if(s[i]=='0') // No contribution due to 0
		            dp[i]=0;
		        else {
		            dp[i]=dp[i+1];
		            if(i<n-1 && (s[i]=='1'||(s[i]=='2'&&s[i+1]<'7'))) // Valid number i and i+1 -> Sum    
		                dp[i]+=dp[i+2];
                    // If Invalid -> Do Nothing
                }
                dp[i]%=mod;
		    }
		    return dp[0];    
		}
};
