class Solution{
public:
    
    // https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1/
    
    int isValid(vector<vector<int>> mat){
        // VALID => every row, every column and (3*3) grid starting from top can contain numbers 1 to 9 only once.
        int n=mat.size();
        int row[n][n], col[n][n], box[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            row[i][j]=col[i][j]=box[i][j]=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]){
                    int x=mat[i][j]-1;
                    int k=3*(i/3)+(j/3); // box index
                    if(row[i][x]||col[j][x]||box[k][x])
                         return 0; 
                    row[i][x]=col[j][x]=box[k][x]=1;
                }
            }
        }
        return 1;
    }
};
