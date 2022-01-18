class Solution {
public:
    
    // https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/
    
	bool isPossible(int n, vector<pair<int, int>>& prerequisites) {
        vector<int> ar[n];   
        vector<int> in(n, 0);
        for(int i=0;i<(int)prerequisites.size();i++){
            ar[prerequisites[i].second].push_back(prerequisites[i].first);
            in[prerequisites[i].first]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++)
            if(in[i]==0)
                q.push(i);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int node: ar[curr]){
                in[node]--;
                if(in[node]==0)
                    q.push(node);
            }
        }
        for(int i=0;i<n;i++)
            if(in[i]!=0)
                return false;
        return true;
	}
};
