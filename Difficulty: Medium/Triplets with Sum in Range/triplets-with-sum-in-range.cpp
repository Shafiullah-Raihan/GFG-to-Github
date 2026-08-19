class Solution {
  public:


    int countTripletsLessThan(vector<int> &arr, int val) {

        int n = arr.size();

        sort(arr.begin(), arr.end());

        int ans = 0;

        int j, k;

        int sum;

        for (int i = 0; i < n - 2; i++) {


            j = i + 1;
            k = n - 1;


            while (j != k) {

                sum = arr[i] + arr[j] + arr[k];

                if (sum > val)
                    k--;


                else {
                    ans += (k - j);
                    j++;
                }
            }
        }

        return ans;
    }


    int countTriplets(vector<int> &arr, int l, int r) {

        int res;


        res = countTripletsLessThan(arr, r) - countTripletsLessThan(arr, l - 1);

        return res;
    }
};