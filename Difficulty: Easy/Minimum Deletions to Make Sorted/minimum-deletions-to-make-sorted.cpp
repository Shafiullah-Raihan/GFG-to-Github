class Solution {
  public:
    int minDeletions(vector<int>& arr) {

        vector<int> tails;

        for (int num : arr) {

            auto it = lower_bound(tails.begin(), tails.end(), num);

            // Extend LIS if num is greater than all tails
            if (it == tails.end())
                tails.push_back(num);

            // Replace to maintain smallest possible tail
            else
                *it = num;
        }

        return arr.size() - tails.size();
    }
};