class Solution {
public:
    
    // https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
    
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        /*    Method - 1
        vector<int> pre(n+1,0);
        int maxi=0;
        for(int i=0;i<n;i++)
            pre[i+1]=pre[i]+weights[i], maxi=max(maxi,weights[i]);
        int low=maxi, high=pre[n], ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            int range_covered=-1; bool flag=false; // Initialise range_covered with -1
            
            for(int i=1;i<=days;i++){
                range_covered+=upper_bound(pre.begin()+range_covered+1, pre.end(), mid+pre[range_covered+1])-pre.begin()-range_covered-2;
                //cout<<mid<<" "<<i<<" & "<<range_covered<<" "<<weights[range_covered]<<endl;
                if(range_covered==n-1){
                    flag=true;
                    break;
                }
                // range_covered => range covered on the weights array = range covered on pre array - 1
            }
            //cout<<range_covered<<" "<<mid<<" "<<low<<" "<<high<<endl;
            if(flag)
                ans=mid, high=mid-1;
            else
                low=mid+1;
        }
        return ans;
        */
        
        // Method - 2  (better)
        int s=0, maxi=INT_MIN;
        for(int i=0;i<n;i++)
            s+=weights[i], maxi=max(maxi, weights[i]);
        int low=maxi, high=s;
        while(low<high){
            int mid=(low+high)/2;
            int d=0, i=0;
            while(i<n){
                d++;
                int sum=0;
                while(i<n&&(sum+weights[i])<=mid)
                    sum+=weights[i], i++;
                //cout<<i<<" "<<d<<endl;
            }
            //cout<<mid<<" "<<d<<endl;
            if(d>days){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
        
        
    }
};
