class Solution{
    public:
    
    // https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1/
    
    string colName (long long int n)
    {
        string ans="";
        while(n>0) {
            n--;
            int rem=n%26;
            ans=(char)('A'+rem)+ans;
            n/=26;
        }
        return ans;
    }
};
