class Solution
{
    public:
    
    // https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1/
    
    void permutations(string s, string& ans, int i, int k, int n) {
        ans=max(ans, s);
        
        if(k==0||i==n-1)
            return;
            
        char maxi=s[i];
        for(int j=i+1;j<n;j++)
            maxi=max(maxi, s[j]);
        
        if(maxi==s[i])
            permutations(s, ans, i+1, k, n);
        else{
            k--;
            for(int j=i+1;j<n;j++){
                if(s[j]==maxi){
                    swap(s[i], s[j]);
                    permutations(s, ans, i+1, k, n);
                    // back to original
                    swap(s[i], s[j]);
                }
            }
        }
    }
    
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
        // The largest character should be placed on the msb and so on
        // But when there are multiple occurences of the largest character then 
        // swap it with the leftmost maximum, middle maximum or the rightmost maximum
        // So for the right answer we have to try all the permutations of the swappings
        int n=str.length();
        string ans=str;
        permutations(str, ans, 0, k, n);
        return ans;
    }
};
