class Solution {
  public:
  
  
  void placeQueens(int i, vector<int> &cols, vector<int> &leftDiagonal,vector<int> &rightDiagonal, vector<int> &cur, vector<vector<int>> &result) {
      int n = cols.size();

      if(i == n) {
          result.push_back(cur);
          return;
      }


      for(int j = 0; j < n; j++){


          if(cols[j] || rightDiagonal[i + j] || leftDiagonal[i - j + n - 1]) 
              continue;


          cols[j] = 1;
          rightDiagonal[i+j] = 1; 
          leftDiagonal[i - j + n - 1] = 1;
          cur.push_back(j+1);

          placeQueens(i + 1, cols, leftDiagonal, rightDiagonal, cur, result);


          cur.pop_back();
          cols[j] = 0;
          rightDiagonal[i+j] = 0; 
          leftDiagonal[i - j + n - 1] = 0;        
        }
    }
  
  
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<int> cols(n, 0);
        vector<int> leftDiagonal(n*2, 0);
        vector<int> rightDiagonal(n*2, 0);
        vector<int> cur;
        vector<vector<int>> result;

        placeQueens(0, cols, leftDiagonal, rightDiagonal, cur, result);

        return result;
    }
};