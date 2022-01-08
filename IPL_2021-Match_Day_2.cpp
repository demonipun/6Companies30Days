class Solution {
  public:
    
    // https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1
    
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        /*
        // N log K  -------------> Good
        vector<int> ans;
        // Multiset is used to store the elements in sorted order and duplicates are also stored
        multiset<int, greater<int>> s;  // max element first
        for(int i=0;i<n;i++) {
            s.insert(arr[i]);
            if(i>=k-1){
                ans.push_back(*s.begin());
                auto x=s.find(arr[i+1-k]);
                s.erase(x);
            }
        }
        return ans;
        
        // N log K   --------------> Better (Priority Queue)
        vector<int> ans;
        priority_queue<pair<int,int>> pq; // (value, index) pair
        int i=0,j=0;
        while(j<n){
            if(j-i<k-1)
                pq.push({arr[j],j}), j++;
            else{
                pq.push({arr[j],j});
                int x=pq.top().first;
                ans.push_back(x);
                while(!pq.empty()){
                    if(pq.top().second<=i)
                        pq.pop();
                    else
                        break;
                }
                i++,j++;
            }
        }
        return ans; 
        */
        
        // N      --------------------> Best
        vector<int> ans;
        deque<int> dq; // Doubly - Ended Queue => push and pop from front and back
        int i=0;
        while(i<n){
            if(!dq.empty()&&dq.front()==i-k) 
                dq.pop_front();
            while(!dq.empty()&&arr[dq.back()]<=arr[i]) 
                dq.pop_back();
            dq.push_back(i);
            if(i>=k-1) 
                ans.push_back(arr[dq.front()]);
            i++;
        }
        return ans;
    }
};
