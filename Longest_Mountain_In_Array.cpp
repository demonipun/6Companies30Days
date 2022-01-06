class Solution {
public:
    
    // https://leetcode.com/problems/longest-mountain-in-array/
    
    int longestMountain(vector<int>& arr) {
        int n=arr.size(), a=0, b=0, ans=0;
        while(a<n) {
            if(a==n-1)
                break;
            bool flag1=false, flag2=false;
            while(a+1<n&&arr[a]==arr[a+1])
                a++, b++;
            while(a+1<n&&arr[a+1]>arr[a])
                flag1=true, a++;
            while(a+1<n&&arr[a+1]<arr[a])
                flag2=true, a++;
            //cout<<a<<" "<<b<<" "<<ans<<endl;
            if(flag1&&flag2) // 
                ans=max(ans,a-b+1);
            b=a; 
        }
        return ans;
    }
};
