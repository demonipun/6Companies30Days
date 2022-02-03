// https://practice.geeksforgeeks.org/problems/find-the-missing-no-in-string/1/

int missingNumber(const string& s) {
    int n=s.length();
    for(int i=1;i<=6;i++) { // Given : length of each number should be <= 6 digits
        string st=s.substr(0, i);
        int num=stoi(st);   // stoi ---> string to integer
        int next=0, ans=0; bool flag=true;
        for(int j=i;j<n;j++) {
            next=next*10+(s[j]-'0');
            if(next>num){
                if(next==num+1){
                    // Do Nothing
                }
                else if(next==num+2){
                    ans=num+1; // Missing Number
                }
                else{
                    flag=false;
                    break;
                }
                num=next;
                next=0;
            }
        }
        // When will we confirm that we have found the answer
        // 1) We do not find an invalid number
        // 2) We have found the missing number
        // 3) The value of next should be 0 as the next next number shold not be some incomplete value ( 991017 )
        if(flag&&ans!=0&&next==0)
            return ans;
    }
    return -1;
}
