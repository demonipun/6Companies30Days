class Solution{
    public:
    
    // https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1
    
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &nums, int k) {
        int n=nums.size(); // https://leetcode.com/problems/4sum/
        // The biggest problem in this question is that the Quadruples should be "Unique" 
        // => same Quadruples(set of 4 integers) should not be repeated.
        sort(nums.begin(), nums.end()); // The quadruple should be internally sorted
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            if(i>0&&nums[i]==nums[i-1]) // same numbers so same quadruples, then skip the loop
                continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>k)  // no more possible quadruples
                break; 
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<k)  // no possible quadruples with nums[i]
                continue;
                
            for(int j=i+1;j<n-2;j++){
                if(j>i+1&&nums[j]==nums[j-1]) // same numbers so same quadruples, then skip the loop
                    continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>k) // no more possible quadruples
                    break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<k) // no possible quadruples with nums[i]
                    continue;
                    
                int left=j+1,right=n-1;
                while(left<right){
                    int sum=nums[left]+nums[right]+nums[i]+nums[j];
                    if(sum<k) 
                        left++;
                    else if(sum>k) 
                        right--;
                    else{ // sum == k
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});                        
                        do{
                            left++;
                        }while(nums[left]==nums[left-1]&&left<right); // No duplicates
                        do{
                            right--;
                        }while(nums[right]==nums[right+1]&&left<right); // No duplicates
                    }
                }
                
            }
            
        }
        return ans;
    }
};
