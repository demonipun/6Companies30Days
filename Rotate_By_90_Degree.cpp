 // https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/
 
void rotate(vector<vector<int>>& matrix)
{
    // Transpose the matrix. -> row into column && column into row
    int n=matrix.size();
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            swap(matrix[i][j], matrix[j][i]);
    // Reverse Each row. > swap row i and row n-1-i till i<n/2
    for(int i=0;i<n/2;i++)
        for(int j=0;j<n;j++)
            swap(matrix[i][j], matrix[n-1-i][j]);
}
