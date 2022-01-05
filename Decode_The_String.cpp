class Solution{
public:
    
    // https://practice.geeksforgeeks.org/problems/decode-the-string2444/1
    
    string decodedString(string s){
        stack<string> chars; 
        stack<int> nums;
        string res=""; 
        int num=0;
        for(char c : s) {
            if(isdigit(c))
                num=num*10+(c-'0'); 
            else if(isalpha(c)) 
                res+=c;                
            else if(c=='[') {
                chars.push(res); 
                nums.push(num);
                res=""; 
                num=0;
            }
            else if(c==']') {
                string tmp=res;
                for(int i=0;i<nums.top()-1; i++) // Creating nums.top() copies
                    res+=tmp;
                res=chars.top()+res;
                chars.pop(); 
                nums.pop();
            }
        }
        return res;  
    }
};
