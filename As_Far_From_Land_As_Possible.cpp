class Solution {
public:
    
    // https://leetcode.com/problems/as-far-from-land-as-possible/
    
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size(), INF=1e9, ans=0;
        // INF == unreachable
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=1){
                    grid[i][j]=INF;
                    if(i>0)
                        grid[i][j]=min(grid[i][j], grid[i-1][j]+1);
                    if(j>0)
                        grid[i][j]=min(grid[i][j], grid[i][j-1]+1);
                }
            }
        }
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<grid[i][j]<<" ";
            cout<<endl;
        }
        */
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]!=1){
                    if(i<n-1)
                        grid[i][j]=min(grid[i][j], grid[i+1][j]+1);
                    if(j<n-1)
                        grid[i][j]=min(grid[i][j], grid[i][j+1]+1);
                    ans=max(ans, grid[i][j]);
                }
            }
        }
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<grid[i][j]<<" ";
            cout<<endl;
        }
        */
        return (ans==INF) ? -1 : ans-1;
    }
};
