class Solution {
    
    // https://practice.geeksforgeeks.org/problems/find-the-position-of-m-th-item1723/1
    
  public:
    int findPosition(int N , int M , int K) {
        int pos=(M+K-1)%N;
        return pos==0 ? N : pos;
    }
};
