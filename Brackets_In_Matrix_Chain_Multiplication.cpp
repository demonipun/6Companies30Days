class Solution{
public:
    
    // https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1/
    
    string matrixChainOrder(int arr[], int n){
        map<pair<int,int>, string> mp;
        vector<vector<int>> dp(n-1, vector<int>(n-1, 0));
        for(int j=0; j<n-1; j++) {
            int r=0,c=j, len=n-1-j;
            while(c<n-1) {
                if(j==0) {
                    string str="";
                    char ch='A'+c;
                    str=str+ch;
                    mp[{r,c}]=str;
                }
                else if(j==1) {
                    dp[r][c]=arr[r]*arr[c]*arr[c+1];
                    mp[{r,c}]='('+ mp[{r,c-1}]+mp[{r+1,c}]+')';
                }
                else {
                    dp[r][c]=INT_MAX;
                    for(int right=r, down=r+1; right<=c && down<=c; right++, down++) {
                        int operations=dp[r][right]+dp[down][c]+arr[r]*arr[down]*arr[c+1];
                        if(dp[r][c]>operations) {
                            dp[r][c]=operations;
                            mp[{r,c}]='('+mp[{r,right}]+mp[{down,c}]+')';
                        }
                    }
                }
                r++; c++;
            }
        } 
        return mp[{0,n-2}];
    }
};
