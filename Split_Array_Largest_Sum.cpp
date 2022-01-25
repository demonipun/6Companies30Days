class Solution {
public:
    
    // https://leetcode.com/problems/split-array-largest-sum/
    
    int splitArray(vector<int>& nums, int m) {
        int s=0, maxi=INT_MIN, n=nums.size();
        for(int x: nums)
            s+=x, maxi=max(maxi, x);
        int l=maxi, r=s;
        while(l<r){
            int mid=(l+r)/2,  cnt=1, sum=0;
            for(int i=0;i<n;i++){
                sum+=nums[i];
                if(sum>mid){
                    cnt++;
                    sum=nums[i];
                    if(cnt>m)
                        break;
                }
            }
            if(cnt>m)
                l=mid+1;
            else
                r=mid;
        }
        return l;
    }
};
