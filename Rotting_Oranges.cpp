class Solution {
public:
    
    // https://leetcode.com/problems/rotting-oranges/
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<int> x={-1,0,1,0};
        vector<int> y={0,1,0,-1}; 
        queue<pair<int,int>> q;
        int fresh=0; 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)
                    q.push({i,j}); // we push the positions of the rotten oranges
                if(grid[i][j]==1)
                    fresh++;       // number of fresh oranges
            }
        }
        int ans=-1;  
        // BFS
        while(!q.empty()) {
            int sz=q.size();       // only the first sz elements before any insertion gets checked
            while(sz--) {
                pair<int,int> p=q.front();
                q.pop();
                for(int i=0;i<4;i++) {
                    int r=p.first+x[i];
                    int c=p.second+y[i];
                    if(r>=0 && r<m && c>=0 && c<n &&grid[r][c]==1) {
                        grid[r][c]=2;
                        q.push({r,c});
                        fresh--; 
                    } 
                }
            }
            ans++;
        }
        if(fresh>0) 
            return -1; 
        if(ans==-1) 
            return 0; 
        return ans;
    }
};
