class Solution{
public:
    
    // https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1/
    
    int isValid(vector<vector<int>> mat){
        // VALID => every row, every column and (3*3) grid starting from top can contain numbers 1 to 9 only once.
        int n=mat.size();
        vector<vector<bool>> row(n+1, vector<bool>(n+1,false));
        vector<vector<bool>> col(n+1, vector<bool>(n+1,false));
        vector<vector<bool>> box(n+1, vector<bool>(n+1,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]){
                    int k=3*(i/3)+(j/3); // box index
                    if(row[i][mat[i][j]]||col[j][mat[i][j]]||box[k][mat[i][j]])
                        return 0;
                    row[i][mat[i][j]]=true;
                    col[j][mat[i][j]]=true;
                    box[k][mat[i][j]]=true;
                }
            }
        }
        return 1;
    }
};
