class Solution {
public:
    
    // https://leetcode.com/problems/pacific-atlantic-water-flow/
    
    int m, n;
    vector<vector<bool>> pacific, atlantic;
    // pacific = 1 => cells which will drain water into the Pacific Ocean
    // atlantic = 1 => cells which will drain water into the Atlantic Ocean
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j){
        if(visited[i][j])
            return;
        visited[i][j]=true;
        if(i<m-1&&heights[i+1][j]>=heights[i][j]) 
            dfs(heights, visited, i+1, j); 
        if(i>0&&heights[i-1][j]>=heights[i][j]) 
            dfs(heights, visited, i-1, j);
        if(j<n-1&&heights[i][j+1]>=heights[i][j]) 
            dfs(heights, visited, i, j+1); 
        if(j>0&&heights[i][j-1]>=heights[i][j]) 
            dfs(heights, visited, i, j-1);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        m=heights.size(), n=heights[0].size();
        atlantic=pacific=vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            dfs(heights, pacific, i, 0);    // Left se Pacific
            dfs(heights, atlantic, i, n-1); // Right se Atlantic
        }
        for(int i=0;i<n;i++){
            dfs(heights, pacific, 0, i);    // Top se Pacific
            dfs(heights, atlantic, m-1, i); // Bottom se Atlantic 
        }
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(atlantic[i][j]&&pacific[i][j]) // water from this cell will drain into both Pacific and Atlantic Ocean
                    ans.push_back({i,j});
        return ans;
    }
};
