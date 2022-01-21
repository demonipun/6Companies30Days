class Solution {
public:
    
    // https://leetcode.com/problems/koko-eating-bananas/
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1, high=1e9;
        while(low<high){
            int mid=low+(high-low)/2, time=0;
            for(int i=0;i<n;i++)
                time+=(piles[i]+mid-1)/mid;
            //cout<<low<<" "<<high<<" "<<mid<<" "<<time<<endl;
            if(time>h)
                low=mid+1;
            else
                high=mid;
        }
        return low;
    }
};
