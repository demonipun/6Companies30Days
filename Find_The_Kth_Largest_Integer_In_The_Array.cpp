class Solution {
public:
    
    // https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/
    
    static bool cmp(string& a, string& b){
        if(a.size()==b.size())
            return a<b;
        return a.size()<b.size();
    }
    
    string kthLargestNumber(vector<string>& nums, int k) {
        int n=nums.size();
        // Sorting of string using Comparator
        sort(nums.begin(), nums.end(), cmp);
        return nums[n-k];
    }
    
    /*  ---------- Method-2 ----------
    string kthLargestNumber(vector<string>& nums, int k) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,(int)nums[i].length());
        }
        string s="00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
        for(int i=0;i<n;i++){
            if(nums[i].length()<maxi){
                nums[i]=s.substr(0,maxi-nums[i].length())+nums[i];
            }
        }
        sort(nums.begin(),nums.end());
        string ans=""; int j=0;
        while(j<maxi&&nums[n-k][j]=='0')
            j++;
        ans=nums[n-k].substr(j,maxi);
        if(ans=="")
            ans="0";
        return ans;
    }
    */
};
