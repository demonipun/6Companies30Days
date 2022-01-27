class Solution {
public:
    
    // https://leetcode.com/problems/maximum-performance-of-a-team/
    
    const int MOD = 1000000007;
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<long long, long long>> v;
        priority_queue<int, vector<int>, greater<int>> pq;// Min Heap of Speed
        // ( Min efficiency * Sum of speeds ) of k Engineers 
        for(int i=0;i<n;i++)
            v.push_back({efficiency[i], speed[i]});
        sort(v.rbegin(),v.rend()); // according to descending efficiency
        long long sum=0, mini=0, ans=0;
        for(int i=0;i<k;i++){
            sum+=v[i].second;
            pq.push(v[i].second);
            ans=max(ans,(v[i].first)*sum);// at most k hai matlab k se kam bhi ho sakta hai
        }
        //cout<<sum<<" "<<maxi<<endl;
        
        // Size of priority_queue = k
        for(int i=k;i<n;i++){
            if(v[i].second>pq.top()){
                sum-=pq.top(); 
                pq.pop();
                sum+=v[i].second;
                ans=max(ans,(v[i].first)*sum); // current efficiency which is the minimum * Sum of the series
                pq.push(v[i].second);
            }
        }
        return (ans%MOD);
    }
};
