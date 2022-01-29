class Solution{
    public:
    
    // https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1/
    
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        int ans=INT_MAX, maxi=INT_MIN;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // Min Heap
        for(int i=0;i<k;i++){ // ensuring Total Participation
            pq.push({KSortedArray[i][0],i});   // smallest number of the list, list number
            maxi=max(maxi,KSortedArray[i][0]);
        }
        int start_with_min_range=0;
        vector<int> index(k, 0); // keeps track of the current index of the i th. list number
        while(true){
            pair<int,int> p=pq.top(); pq.pop();
            int mini=p.first;
            int range=maxi-mini;
            if(range<ans){
                ans=range;
                start_with_min_range=mini;
            }
            index[p.second]++; // index number of particular array
            if(index[p.second]==n)
                break;
            pq.push({KSortedArray[p.second][index[p.second]],p.second}); // list containing the smallest value is incremented
            // In each step, the priority queue contains only k elements with the maximum element as maxi
            maxi=max(maxi,KSortedArray[p.second][index[p.second]]);
        }
        return {start_with_min_range,start_with_min_range+ans};
    }
};
