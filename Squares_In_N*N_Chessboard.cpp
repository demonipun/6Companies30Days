class Solution {
  public:
    
    // https://practice.geeksforgeeks.org/problems/squares-in-nn-chessboard1801/1
    
    long long squaresInChessBoard(long long n) {
        // Number of 1*1 squares = n*n
        // Number of 2*2 squares = (n-1)*(n-1)
        // ...
        // Number of n*n squares = 1*1
        // Total squares = 1*1+2*2+ ... +n*n
        return n*(n+1)*(2*n+1)/6;
    }
};
