// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    // https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1
    
    vector<string> ans;
    
    void generate(string sequence, int len, int balance, int n) {
        if(len>n)
            return;
        if(len==n&&balance==0){
            ans.push_back(sequence);
            return;
        }
        if(balance<n)
            generate(sequence+"(", len+1, balance+1, n);
        if(balance!=0)
            generate(sequence+")", len, balance-1, n);
    }
    
    vector<string> AllParenthesis(int n) {
        generate("(", 1 , 1, n); // current character , number of open parentheses , balance , max. length
        return ans;
    }
};
