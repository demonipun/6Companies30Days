class Solution{
public:
    
    // https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
    
    int equalPartition(int n, int arr[])
    {
        // This question is very much similar to Minimum Sum Partition (gfg)
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=arr[i];
        if(sum%2)
            return 0;
        int dp[n+1][(sum/2)+1];
        // dp[i][j] == 1, if sum = j can be made by using atmost i elements from the array, else 0
        for(int j=0;j<=(sum/2);j++) // it is not possible to make any sum using no elements from the array
            dp[0][j]=0;
        for(int i=0;i<=n;i++)       // it is possible to make sum = 0 with all elements from 1 to n
            dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=(sum/2);j++){
                dp[i][j]=dp[i-1][j];
                if(j>=arr[i-1])
                    dp[i][j]=(dp[i][j]||dp[i-1][j-arr[i-1]]);
            }
        }
        return dp[n][(sum/2)];
    }
};
