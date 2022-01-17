class Solution{
  public:
    
    // https://practice.geeksforgeeks.org/problems/implement-atoi/1/
    
    int atoi(string str) {
        int n=str.length(), ans=0;
        bool flag=false;
        for(int i=0;i<n;i++) {
            if(i==0&&str[i]=='-')
                flag=true;
            else if(str[i]>='0'&&str[i]<='9')
                ans=ans*10+(str[i]-'0');
            else
                return -1;
        }
        if(flag)
            ans=-ans;
        return ans;
    }
};
