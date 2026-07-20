


class Solution {

  public:
    int find(vector<int>& arr) {
        int num = 0;

        int n = arr.size();

        for (int i = n - 1; i >= 0; i--) {

          
            num = round((double)(arr[i] + num) / 2.0);
        }

        // Return the final value of num
        return num;
    }
};