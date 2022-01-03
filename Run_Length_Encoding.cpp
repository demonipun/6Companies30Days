// https://practice.geeksforgeeks.org/problems/run-length-encoding/1/#

string encode(string src)
{     
    int n=src.length();
    string ans="";
    for(int i=0;i<n;i++) {
        int cnt=0; char ch=src[i];
        while(i<n&&src[i]==ch)
            cnt++, i++;
        ans+=ch;
        ans+=to_string(cnt);
        i--;
    }
    return ans;
}  
