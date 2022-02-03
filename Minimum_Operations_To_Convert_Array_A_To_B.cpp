class Solution {
  public:
    
    // https://practice.geeksforgeeks.org/problems/minimum-insertions-to-make-two-arrays-equal/1
    
    int LIS(vector<int>& v){
        int n=v.size();
        if(n==0)      // vector v is empty
            return 0;
        vector<int> dp;
        dp.push_back(v[0]);
        for(int i=1;i<n;i++){
            if(v[i]>dp.back())
                dp.push_back(v[i]);
            else{
                auto pos=lower_bound(dp.begin(),dp.end(),v[i])-dp.begin();
                dp[pos]=v[i];
            }
        }
        return (int)dp.size();
    }
    
    int minInsAndDel(int A[], int B[], int N, int M) {
        // Trivial solution would be to use 2-D DP
        // First delete the numbers in A which are not in B
        // Now we need to find LCS between A and B, and keep those elements in A and delete rest, 
        // and also add remaining numbers in B which don't occur in the LCS to make it equal to B
        // To find the LCS(Longest Common Subsequence) with trivial 2-D DP will give TLE, but since B is already sorted,
        // Longest Increasing Subsequence in A will be the LCS which can be found in O(N*LogN) time
        vector<int> v;
        unordered_set<int> s;
        for(int i=0;i<M;i++)
            s.insert(B[i]);
        for(int i=0;i<N;i++)
            if(s.find(A[i])!=s.end())
                v.push_back(A[i]); 
        // Since B in sorted ===> LIS in A will be LCS
        int LCS=LIS(v);
        // Total operations = Elements deleted + Elements added = M - LCS + N - LCS 
        return N+M-2*LCS;
    }
};
