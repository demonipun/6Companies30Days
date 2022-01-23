class Solution {
public:
    
    // https://leetcode.com/problems/course-schedule-ii/
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        const int n = numCourses;
        vector<int> ar[n];  // Graph
        vector<int> in(n);  // In Degree
        vector<int> res;    // Answer Array
        
        for(int i=0;i<(int)prerequisites.size();i++)
            ar[prerequisites[i][1]].push_back(prerequisites[i][0]), in[prerequisites[i][0]]++;
        
        queue<int> q;
        
        for(int i=0; i<n; i++)
            if(in[i]==0)
                q.push(i), res.push_back(i);
        
        while(!q.empty()&&res.size()!=numCourses){
            int curr=q.front(); q.pop(); 
            
            for(int node: ar[curr]){
                in[node]--;
                if(in[node]==0){
                    res.push_back(node);
                    q.push(node);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(in[i]!=0){
                res.clear(); 
                break;
            }
        }
        
        return res;
    }
};
