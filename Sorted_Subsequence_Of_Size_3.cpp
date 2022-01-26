class Solution{
  public:
    
    // https://practice.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1/
    
    vector<int> find3Numbers(vector<int> arr, int N) {
        vector<int> small(N, 1e9), large(N, -1e9);
        int mini=1e9, maxi=-1e9;
        for(int i=0;i<N-1;i++) {    // piche wala small
            mini=min(mini, arr[i]);
            small[i+1]=mini;
        }
        for(int i=N-1;i>0;i--) {    // aage wala large
            maxi=max(maxi, arr[i]);
            large[i-1]=maxi;
        }
        for(int i=1;i<N-1;i++)
            if(arr[i]>small[i]&&arr[i]<large[i])
                return {small[i], arr[i], large[i]}; 
        return {};
    }
};
