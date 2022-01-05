class Solution {
public:
    
    // https://leetcode.com/problems/minimum-size-subarray-sum/
    
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(), a=0, b=0, ans=INT_MAX, sum=0;
        while(a<n) {
            while(a<n&&sum<target)
                sum+=nums[a], a++;
            while(b<a&&sum>=target)
                ans=min(ans,a-b), sum-=nums[b], b++;
        }
        return ans==INT_MAX ? 0 : ans;
    }
};
