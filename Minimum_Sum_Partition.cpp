class Solution{

  public:
    
    // https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/
    
	int minDifference(int arr[], int n)  { 
	   int sum=0;
	   for(int i=0;i<n;i++)
	       sum+=arr[i];
	   int dp[n+1][(sum/2)+1];
	   // dp[i][j] = {1 if some subset from 1st to ith element has a sum equal to j , else 0 otherwise} 
	   for(int i=0;i<=n;i++) {
	       for(int j=0;j<=(sum/2);j++) {
	           if(j==0)         // sum 0 can always be made by not selecting any number from the array
	               dp[i][j]=1;  // n times
	           else if(i==0)    // by using 0 elements from the array no sum can be made
	               dp[i][j]=0;  // sum/2 times
	           else {
	               dp[i][j]=dp[i-1][j];
	               if(j>=arr[i-1])
	                   dp[i][j]=dp[i][j]||dp[i-1][j-arr[i-1]];
	           }
	       }
	   }
	   int ans=INT_MAX;
	   for(int i=0;i<=(sum/2);i++)
	       if(dp[n][i])
	           ans=min(ans, abs(sum-2*i));
	   return ans;
	}
};
