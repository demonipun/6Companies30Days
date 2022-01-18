class Solution
{   
    public: 
    
    // https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1/
    
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c) 
    {
        // left to right
        // top to bottom 
        // right to left 
        // bottom to top
        int A=0, B=0, C=r-1, D=c-1, index=0;
        //  A=left  B=top  C=bottom  D=right  
        vector<int> ans(r*c);
        while(index<r*c) {
            for(int i=A;i<=D;i++) 
                ans[index++]=matrix[B][i];
            B++;
            for(int i=B;i<=C;i++) 
                ans[index++]=matrix[i][D];
            D--;
            if(index==r*c) 
                break;
            for(int i=D;i>=A;i--) 
                ans[index++]=matrix[C][i];
            C--;
            for(int i=C;i>=B;i--) 
                ans[index++]=matrix[i][A];
            A++;
        }
        return ans;
    }
};
