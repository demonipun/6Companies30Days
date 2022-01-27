class Solution
{
	public:
	
	// https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1
	
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Bridge => removing the edge disconnects the graph.
        vector<bool> vis(V, false);
        queue<int> q;
        q.push(c);
        while(!q.empty()) {
            int curr=q.front(); q.pop();
            vis[curr]=true;
            for(int x: adj[curr]){
                if(x==d&&curr!=c) {
                    //cout<<curr<<" "<<x<<endl;
                    return 0;
                }
                if(!vis[x]&&!(curr==c&&x==d)) // Not visited and not ( c-d )
                    q.push(x);
            }
        }
        return 1;
    }
};
