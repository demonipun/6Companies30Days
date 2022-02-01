class Solution {
public:
    
    // https://leetcode.com/problems/path-with-maximum-probability/
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double>> ar[n];
        int m=edges.size();
        for(int i=0;i<m;i++){
            int A=edges[i][0], B=edges[i][1];
            ar[A].push_back({B, succProb[i]});
            ar[B].push_back({A, succProb[i]});
        }
        priority_queue<pair<double,int>> pq; // Min Heap
        vector<double> dist(n, 0);
        pq.push({1, start}); dist[start]=1; // Distance, Node
        while(!pq.empty()){
            int curr=pq.top().second;
            double curr_d=pq.top().first;
            pq.pop();
            for(pair<int, double> edge: ar[curr]){
                if((curr_d*edge.second)>dist[edge.first]){
                    dist[edge.first]=(curr_d*edge.second);
                    pq.push({dist[edge.first],edge.first});
                }
            }
        }
        return dist[end];
    }
};
