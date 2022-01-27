class Solution
{
    public:
    
    // https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/
    
    int dx[8]={1, 0, -1, 0, 1, -1, -1, 1};
    int dy[8]={0, 1, 0, -1, 1, -1, 1, -1};
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int n, int m, int i, int j, int& cnt){
        cnt++;
        vis[i][j]=true;
        for(int k=0;k<8;k++)
            if((i+dx[k])>=0&&(i+dx[k])<n&&(j+dy[k])>=0&&(j+dy[k])<m&&grid[i+dx[k]][j+dy[k]]&&!vis[i+dx[k]][j+dy[k]]) // all check
                dfs(grid, vis, n, m, i+dx[k], j+dy[k], cnt);
    }
    
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size(), ans=0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++){
                if(grid[i][j]&&!vis[i][j]){
                    int cnt=0;
                    dfs(grid, vis, n, m, i, j, cnt);
                    ans=max(ans,cnt);
                }
            }
        }
        return ans;
    }
};
