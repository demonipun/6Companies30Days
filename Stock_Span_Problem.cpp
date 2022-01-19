class Solution
{
    public:
    
    // https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
    
    //Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
        vector<int> ans(n);
        stack<int> s;  // Using Decreasing Stack
        for(int i=0;i<n;i++){
            while(!s.empty()&&price[s.top()]<=price[i])
                s.pop();
            ans[i]=(i-(!s.empty() ? s.top() : -1));
            s.push(i);
        }
        return ans;
    }
};
