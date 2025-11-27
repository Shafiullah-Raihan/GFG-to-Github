class Solution {
public:
    int subsetXORSum(vector<int>& arr) {
        int n = arr.size();
        int orAll = 0;
        for (int x : arr) {
            orAll |= x;  
        }

       
        return orAll * (1 << (n - 1));
    }
};
