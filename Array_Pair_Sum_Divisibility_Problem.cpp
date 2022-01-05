class Solution {
  public:
    
    // https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1
    // Array can be divided into pairs => The whole array divided into groups of length 2 (pair) only
    
    bool canPair(vector<int> nums, int k) {
        int n=(int)nums.size();
        if(n%2)
            return false;
        vector<int> mp(k,0);
        for(int x: nums) 
            mp[x%k]++;
        if(mp[0]%2)
            return false;
        int i=1,j=k-1;
        while(i<j) {
            if(mp[i]!=mp[j])
                return false;
            i++;
            j--;
        }
        if(i==j&&mp[i]%2) // k is Even
            return false;
        return true;
    }
};
