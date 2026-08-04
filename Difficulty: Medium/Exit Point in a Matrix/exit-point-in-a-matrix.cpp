class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int i = 0, j = 0;
        int dir = 1;

        while (i < n && j < m && i >= 0 && j >= 0) {

            if (mat[i][j] == 1) {
                mat[i][j] = 0;
                switch (dir) {
                    case 1:
                        dir = 2;
                        break;
                    case 2:
                        dir = 3;
                        break;
                    case 3:
                        dir = 4;
                        break;
                    case 4:
                        dir = 1;
                        break;
                }
            }

            switch (dir) {
                case 1:
                    j++;
                    break; 
                case 2:
                    i++;
                    break; 
                case 3:
                    j--;
                    break;
                case 4:
                    i--;
                    break;
            }
        }

        switch (dir) {
            case 1:
                j--;
                break;
            case 2:
                i--;
                break;
            case 3:
                j++;
                break;
            case 4:
                i++;
                break;
        }

        return {i, j};
    }
};