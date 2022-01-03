class Solution {
  public:
    
    // https://practice.geeksforgeeks.org/problems/overlapping-rectangles1924/1/
  
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        //Rect2 in LHS || Rect1 in LHS
        if(L1[0]>R2[0] || L2[0]>R1[0])
            return false;
        //Rect1 is Down|| Rect2 is Down 
        if(L1[1]<R2[1] || L2[1]<R1[1])
            return false;
        return true;
    }
};
