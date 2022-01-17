class Solution
{
    public:
    
    // https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
    
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        int a=0, b=0;
        long long sum=0;
        while(b<=n) {
            if(sum==s)
                return {a+1, b};
            if(b==n)
                return {-1};
            while(b<n&&sum<s) 
                sum+=arr[b++];
            while(a<b&&sum>s)
                sum-=arr[a++];
        }
    }
};
