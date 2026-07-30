class Solution {
  public:
    int maxSubsetXOR(vector<int> &arr) {
        int n = arr.size();
        int index = 0;

        for (int bit = 31; bit >= 0 && index < n; bit--) {

            int maxIndex = index;

            for (int i = index; i < n; i++) {
                if ((arr[i] & (1 << bit)) && arr[i] > arr[maxIndex]) {
                    maxIndex = i;
                }
            }

            if ((arr[maxIndex] & (1 << bit)) == 0) {
                continue;
            }

            swap(arr[index], arr[maxIndex]);

            for (int i = 0; i < n; i++) {
                if (i != index && (arr[i] & (1 << bit))) {
                    arr[i] ^= arr[index];
                }
            }

            index++;
        }

        int ans = 0;

        for (int num : arr) {
            ans ^= num;
        }

        return ans;
    }
};