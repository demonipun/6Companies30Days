class Solution{
  public:
    
    // https://practice.geeksforgeeks.org/problems/next-higher-palindromic-number-using-the-same-set-of-digits5859/1/
    
    string nextPalin(string s) { 
        int n=s.length();  
        if(n<=3) 
            return "-1";
        string half=s.substr(0,n/2);
        // input s is already a palindrome
        if(next_permutation(half.begin(),half.end())) {
            string ans=half;
            if(n&1)     // if n is odd then add the middle character
                ans+=s[n/2];
            reverse(half.begin(),half.end());
            ans+=half;  // adding the reverse
            return ans;
        }
        return "-1";
    }
};
