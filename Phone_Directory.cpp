class Solution{
public:
    
    // https://practice.geeksforgeeks.org/problems/phone-directory4628/1/
    
    vector<vector<string>> displayContacts(int n, string contact[], string S)
    {
        // Ideally can be solved using Tries
        
        set<string> s;  // store the contact list in sorted order
        for(int i=0; i<n; i++)
            s.insert(contact[i]);
        vector<string> v;
        for(auto itr=s.begin(); itr!=s.end(); itr++)
            v.push_back(*itr);
        vector<vector<string>> ans;
        int m=S.length();
        for(int i=1;i<=m;i++){
            string key=S.substr(0, i);
            vector<string> temp;
            for(string x: v)
                if(x.substr(0,i)==key)
                    temp.push_back(x);
            if(temp.empty())
                ans.push_back({"0"});
            else
                ans.push_back(temp);
        }
        return ans;
    }
};
