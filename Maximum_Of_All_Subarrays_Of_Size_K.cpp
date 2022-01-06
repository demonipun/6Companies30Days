class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    
    // https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
    
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
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
    }
};
