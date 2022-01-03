class Solution{
  public:
    
    // https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/#
    
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int ans=0, j=0;
        long long p=1;
        for(int i=0;i<n;i++) {
            p=p*a[i];
            while(j<=i&&p>=k) 
                p=p/a[j], j++;
            ans+=(i+1-j);
        }
        return ans;
    }
};
