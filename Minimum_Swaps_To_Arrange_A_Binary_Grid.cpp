class Solution {
public:
    
    // https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/
    
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size(), ans=0;
        // row 0-> n-1 0's from back atleast
        // row 1-> n-2 0's from back atleast
        // .....
        // row n-1-> no 0's from back atleast
        vector<int> cnt0(n,0);
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=n-1;j>=0;j--){ // Count from back
                if(grid[i][j]==0) 
                    cnt++;
                else 
                    break;
            }
            cnt0[i]=cnt;
        }
        for(int i=0;i<n;i++){
            int zeroes=n-1-i, j=i;
            // Why Greedy works?  -> kyuki the lagest number of 0's is required first AND we can greedily find the smallest index having value >= the required number of 0's
            // Uske baad jitne 0's required honge wo current se kam hi honge, so we can choose greedily
            while(j<n && cnt0[j]<zeroes)
                j++;
            if(j==n)      // Not Found
                return -1;
            ans+=(j-i);
            while(j>i)    // Effect Of Swappings
                cnt0[j]=cnt0[j-1], j--;
        }    
        return ans;
    }
};
