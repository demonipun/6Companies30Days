class Solution{
public:	
    
    // https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1
    
	void matchPairs(char nuts[], char bolts[], int n) {
	    // Map sorts the characters in ascending Order
	    map<char, int> mp;
	    for(int i=0;i<n;i++)
	        mp[nuts[i]]=1;
	    int k=0;
	    // To avoid nut-to-nut bolt-to-bolt comparison, we iterate through the map
	    for(auto itr=mp.begin();itr!=mp.end();itr++) {
	        if(itr->second) {
	            nuts[k]=itr->first;
	            bolts[k]=nuts[k];
	            k++;
	        }
	    }
	}

};
