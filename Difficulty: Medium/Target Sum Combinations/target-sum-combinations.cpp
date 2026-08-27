class Solution {
  public:
    void combinationSumUtil(vector<int>& A, int sum, vector<vector<int>>& result, vector<int>& current, int pos) {
        if (sum == 0) {
            result.push_back(current);
            return;
        }
        
        if (sum < 0 || pos >= A.size()) {
            return;
        }

        current.push_back(A[pos]);
        combinationSumUtil(A, sum - A[pos], result, current, pos); 
        current.pop_back();

        combinationSumUtil(A, sum, result, current, pos + 1);
    }
    vector<vector<int>> targetSumComb(vector<int>& A, int B) {
        // code here
        sort(A.begin(), A.end());
        vector<vector<int>> result;
        vector<int> current;
        vector<int> C;

        for (int i = 0; i < A.size(); i++) {
            if (i == 0 || A[i] != A[i - 1]) { 
                C.push_back(A[i]);
            }
        }

      
        combinationSumUtil(C, B, result, current, 0);

        return result;
        
    }
};

