class Solution {
public:
    
    // https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
    
    bool winnerOfGame(string colors) {
        int n=colors.length();
        int a=0, b=0; // a -> Alice's points & b -> Bob's points
        for(int i=2;i<n;i++){
            if(colors[i]==colors[i-1]&&colors[i]==colors[i-2]){
                if(colors[i]=='A')
                    a++;
                else
                    b++;
            }
        }
        return (a>b);
    }
};
