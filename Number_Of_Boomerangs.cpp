class Solution {
public:
    
    // https://leetcode.com/problems/number-of-boomerangs/
    
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size(), ans;
        for(int i=0;i<n;i++){
            unordered_map<int,int> mp;
            for(int j=0;j<n;j++){
                if(i==j)
                    continue;
                int dx=points[i][0]-points[j][0];
                int dy=points[i][1]-points[j][1];
                mp[dx*dx+dy*dy]++;
            }
            // the number of permutations of choosing 2 out of n = nP2 => n!/(n-2)! = n*(n-1)
            for(auto x: mp)
                ans+=(x.second)*(x.second-1);
        }
        return ans;
    }
};
