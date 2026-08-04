class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {

        sort(arr.begin(), arr.end());

        int s = 0;
        int total = 0;

        for (int i = 1; i < arr.size(); i++) {

            while (s < i && arr[i] - arr[s] >= k) {
                s++;
            }

            total += i - s;
        }

        return total;
    }
};