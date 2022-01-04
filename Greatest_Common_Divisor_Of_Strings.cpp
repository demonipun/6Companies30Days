class Solution {
public:
    
    // https://leetcode.com/problems/greatest-common-divisor-of-strings/
    
    string gcdOfStrings(string str1, string str2) {
        string s= str1.length() >= str2.length() ? str1 : str2, p = str1.length() < str2.length() ? str1 : str2;
        int maxi=s.length(), mini=p.length();
        //cout<<maxi<<" "<<mini<<endl;
        for(int i=mini;i>0;i--){
            //cout<<i<<" "<<endl;
            bool flag1=true, flag2=true;
            if(maxi%i!=0||mini%i!=0)  
                continue;
            // i is factor of both maxi and mini 
            string temp=p.substr(0,i);
            for(int j=0;j+i<=mini;j=j+i){
                if(p.substr(j,i)!=temp){
                    flag1=false; 
                    break;
                }
            }
            if(!flag1)
                continue;
            for(int j=0;j+i<=maxi;j=j+i){
                if(s.substr(j,i)!=temp){
                    flag2=false; 
                    break;
                }
            }
            if(flag1&&flag2)
                return temp;
        }
        return "";
    }
};
