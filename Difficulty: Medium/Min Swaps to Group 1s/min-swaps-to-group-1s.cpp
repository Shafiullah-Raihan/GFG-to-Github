class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // code here
        int n = arr.size();
    int numberOfOnes = 0;

    // find total number of all 1's in the array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            numberOfOnes++;
    }
    if (numberOfOnes == 0)
        return -1;
        
    // length of subarray to check for
    int x = numberOfOnes;

    int count_ones = 0, maxOnes;

    // Find 1's for first subarray of length x
    for (int i = 0; i < x; i++)
    {
        if (arr[i] == 1)
            count_ones++;
    }

    maxOnes = count_ones;

    // using sliding window technique to find
    // max number of ones in subarray of length x
    for (int i = 1; i <= n - x; i++)
    {

        if (arr[i - 1] == 1)
            count_ones--;

        if (arr[i + x - 1] == 1)
            count_ones++;

        if (maxOnes < count_ones)
            maxOnes = count_ones;
    }

    // calculate number of zeros in subarray
    // of length x with maximum number of 1's
    int numberOfZeroes = x - maxOnes;

    return numberOfZeroes;
        
    }
};