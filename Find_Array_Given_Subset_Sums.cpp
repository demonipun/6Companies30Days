class Solution {
public:
    
    // https://leetcode.com/problems/find-array-given-subset-sums/
    
    vector<int> recoverArray(int n, vector<int>& sums) {
        vector<int> ans;
        sort(sums.begin(), sums.end());
        while(n--) {
            // We make n iterations and in each iteration we decide a number of the Original array
            // In every iteration we have a sorted array and in every iteration Size of sums array = 1/2 * Size in the previous iteration
            // We take the difference between two smallest elements  => diff = sums[1] - sums[0]
            // CLAIM : Either 'diff' or '-diff' is a part of the Original array
            // Eg. {-1, -2} ---> {-3, -2, -1, 0}  -------> -diff is a part of the Original array
            // Eg. {1, 2}   ---> {0, 1, 2, 3}     ------->  diff is a part of the Original array
            // Why is diff or -diff a part of the array ?
            // ~>> smallest element + diff = second smallest element OR second smallest element + -diff = smallest element
            // So this diff or -diff must be a part of the Original array, since the one number can be from another number using an element of the Original array
            
            // In each iteration, the only decision we need to make is whether to push 'diff' in answer array or '-diff' in answer array
            // Now the only problem is whether to push diff or -diff in yhe Original array and how to go about the computation
            // If diff is an element Original array, then there are 2^(n/2) elements out of 2^n elements using diff to form a new subset sum (including 0->{})
            // Group 1 (containing diff)  -> frequency of Group 2 => (x+diff) will be increased
            // Group 2 (containing -diff) -> frequency of Group 1 => (x) -----> (x+diff-diff) will be decreased
            // Group 2 will be executed if freq[x] > 0
            // Whichever group out of A and B contains 0 will be taken as the input array for the next iteration
            
            // for(int x: sums) cout<<x<<" "; cout<<endl;
            
            int diff=sums[1]-sums[0]; 
            unordered_map<int, int> freq; 
            vector<int> A, B; 
            bool flag=false; 
            for(int x: sums) {
                if(freq[x]==0) {
                    A.push_back(x); 
                    freq[x+diff]++; 
                    if(x==0) 
                        flag=true;  // We need to take vector A
                } 
                else {
                    B.push_back(x); 
                    freq[x]--; 
                }
            }
            if(flag){
                ans.push_back(diff); 
                sums=A; 
            } 
            else {
                ans.push_back(-diff); 
                sums=B; 
            }
        }
        return ans; 
    }
};
