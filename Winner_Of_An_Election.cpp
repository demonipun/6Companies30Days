class Solution{
  public:
  
    // https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1/
    
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        string winner; int winner_cnt=0;
        unordered_map<string, int> mp;
        for(int i=0;i<n;i++) {
            mp[arr[i]]++;
            if(mp[arr[i]]>winner_cnt||(mp[arr[i]]==winner_cnt&&arr[i]<winner)) {
                winner=arr[i];
                winner_cnt=mp[arr[i]];
            }
        }
        return {winner, to_string(winner_cnt)};
    }
};
