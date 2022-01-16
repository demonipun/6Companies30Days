class Solution{
    public:
    
    // https://practice.geeksforgeeks.org/problems/amend-the-sentence3235/1
    
    string amendSentence(string s)
    {
        string ans="";
        bool allow=false;
        for(char ch : s){
            if(ch<=90){
                if(allow)
                    ans+=' ';
                ans+=(char)(ch+32);
            }
            else
                ans+=ch;
            allow=true;
        }
        return ans;
    }
};
