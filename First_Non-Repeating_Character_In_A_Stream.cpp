class Solution {
    
    // https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
    
	public:
		string FirstNonRepeating(string s){
		    queue<int> q;
		    vector<int> f(26,0);
		    for(int i=0;i<s.length();i++){
		        f[s[i]-'a']++;
		        if(f[s[i]-'a']==1)
		            q.push(s[i]);
		        while(!q.empty()&&f[q.front()-'a']!=1)
		            q.pop();
		        if(q.empty())
		            s[i]='#';
		        else
		            s[i]=q.front();
		    }
		    return s;
		}
};
