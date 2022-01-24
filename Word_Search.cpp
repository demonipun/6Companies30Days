class Solution {
public:
    
    bool dfs(vector<vector<char>>& board, string word, int n, int m, int i, int j, int k){
        if(k==word.length())       // word formed or not
            return true;
        if(i<0||i>=n||j<0||j>=m)   // valid or not
            return false;
        if(word[k]==board[i][j]){
            char temp=board[i][j]; // storing the value of the character
            board[i][j]='#';       // whichever character is taken into final is marked as destroyed
            
            bool a=dfs(board, word, n, m, i+1, j, k+1); 
            bool b=dfs(board, word, n, m, i-1, j, k+1);
            bool c=dfs(board, word, n, m, i, j+1, k+1);
            bool d=dfs(board, word, n, m, i, j-1, k+1);
            
            board[i][j]=temp;      // character is restored back after the check for the word
            return a||b||c||d;
        }
        return false;
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n=board.size(), m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j])
                    if(dfs(board, word, n, m, i, j, 0))
                        return true;
            }
        }
        return false;
    }
};
