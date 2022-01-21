class Solution {
public:
    
    // https://leetcode.com/problems/number-of-provinces/submissions/
    // Counting The Number Of Components - The Traditional Way
    
    void dfs(vector<int> ar[], vector<bool>& visited, int node){
        visited[node]=true;
        for(int child: ar[node])
            if(!visited[child])
                dfs(ar, visited, child);
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> ar[n];
        vector<bool> visited(n, false);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(i!=j&&isConnected[i][j]==1)
                    ar[i].push_back(j);
        int components=0;
        for(int i=0;i<n;i++){
            // cout<<i<<" "<<visited[i]<<endl;
            if(!visited[i])
                components++, dfs(ar, visited, i);
        }
        return components;
    }
};
