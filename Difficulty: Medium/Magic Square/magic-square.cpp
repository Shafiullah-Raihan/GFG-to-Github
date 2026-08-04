class Solution {
  public:
    bool magicSquare(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int target = n * (n*n + 1) / 2;
        vector<bool> seen(n*n + 1, false);
        
        int diag1 = 0, diag2 = 0;
        for(int i = 0; i < n; i++) {
            int rowSum = 0, colSum = 0;
            for(int j = 0; j < n; j++) {
                int valRow = mat[i][j];
                int valCol = mat[j][i];
                
                if(valRow < 1 || valRow > n*n || seen[valRow]) return 0;
                seen[valRow] = true;
                
                rowSum += valRow;
                colSum += valCol;
                
                if(i == j) diag1 += valRow;
                if(i + j == n-1) diag2 += valRow;
            }
            if(rowSum != target || colSum != target) return 0;
        }
        
        if(diag1 != target || diag2 != target) return 0;
        return 1;
    }
};