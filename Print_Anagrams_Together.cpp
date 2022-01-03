class Solution{
  public:
  
    // https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/
    // Anagram - a word, phrase, or name formed by rearranging the letters of another, such as spar, formed from rasp.
    
    vector<vector<string>> Anagrams(vector<string>& s) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            string copy=s[i];
            sort(s[i].begin(), s[i].end());
            mp[s[i]].push_back(copy);
        }
        for(auto x: mp)
            ans.push_back(x.second);
        return ans;
    }
};
