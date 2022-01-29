class Solution
{
    public:
    
    // https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/
    
    vector<vector<char>> letters={{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},
                                        {'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}}; // 0 1 2 3 4 5 6 7 8 9
    void solve(vector<string>& ans, string digits, int i, int k, string curr, int len){
        if(i>=len) 
            return;
        if(k>=letters[((int)digits[i]-'0')].size()) 
            return;
        string temp=curr;
        curr=curr+letters[((int)digits[i]-'0')][k];
        if(i==len-1)
            ans.push_back(curr);
    
        solve(ans,digits,i+1,0,curr,len);
        solve(ans,digits,i,k+1,temp,len);
    }
    vector<string> possibleWords(int a[], int N) {
        if(N==0)
            return {};
        vector<string> ans;
        string digits="";
        for(int i=0;i<N;i++)
            digits+=to_string(a[i]);
        // digits -> sequence of numbers typed by the user as a string
        solve(ans,digits,0,0,"",digits.size());
        return ans;
    }
};
