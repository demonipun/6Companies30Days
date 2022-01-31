class Solution{
    public:
    
    // https://practice.geeksforgeeks.org/problems/alien-dictionary/1/
    
    void topo(unordered_set<int> adj[], vector<bool> &vis, string &ans, int u) {
        vis[u]=true;
        for(auto i:adj[u])
            if(!vis[i])
                topo(adj, vis, ans, i);
        ans.insert(ans.begin(),'a'+(char)u); 
    }
    
    string findOrder(string dict[], int N, int K) {
        unordered_set<int> adj[K];
        // dict is sorted
        for(int i=0;i<N-1;i++) {
            for(int j=0;j<min(dict[i].length(),dict[i+1].length());j++) {
                if(dict[i][j]!=dict[i+1][j]) { // first uncommon letter between consecutive words decides the order 
                    adj[dict[i][j]-'a'].insert(dict[i+1][j]-'a'); // Smaller character -> Larger character
                    break;
                }
            }
        }
        string ans;
        vector<bool> vis(K,false);
        for(int i=0;i<K;i++)
            if(!vis[i])
                topo(adj, vis, ans, i);
        // Characters not present in string have higher precedence
        // cout<<ans<<endl;
        return ans;
    }
};
