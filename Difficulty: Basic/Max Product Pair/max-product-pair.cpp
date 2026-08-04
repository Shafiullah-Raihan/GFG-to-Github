class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        int max = 0, secondMax = 0;

        for (int i = 0; i < n; i++) {

            if (arr[i] >= max) {


                secondMax = max;
                max = arr[i];
            }

            else if (arr[i] >= secondMax) {

                secondMax = arr[i];
            }
        }

        return max * secondMax;
    }
};