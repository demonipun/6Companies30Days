class Solution{   
public:
    
    // https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1
    
    string printMinNumberForPattern(string s){
        stack<int> st;
        string ans="";
        int x=1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='D')
                st.push(x++);
            else {
                st.push(x++);
                while(!st.empty())
                    ans+=char(st.top()+'0'), st.pop();
            }
        }
        st.push(x);
        while(!st.empty())
            ans+=char(st.top()+'0'), st.pop();
        return ans;
    }
};
