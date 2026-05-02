class Solution {
  public:
    int countBits(int n){
    int cnt = 0;
    while (n > 0)
    {
        cnt += (n & 1);
        n = n >> 1;
    }
    return cnt;
}

// Function to sort an array according to bit count
vector<int> sortBySetBitCount(vector<int> &arr)
{
    int n = arr.size();

    // Create a 2d array to map array elements
    // to their corresponding set bit count
    vector<vector<int>> count(32);

    // insert elements in the 2d array
    for (int i = 0; i < n; i++)
    {
        int setBit = countBits(arr[i]);
        count[setBit].push_back(arr[i]);
    }

    // vector to store ans
    vector<int> res;

    // Traverse through all bit counts
    for (int i = 31; i >= 0; i--)
    {
        // Traverse through all elements
        // of current bit count
        for (int k = 0; k < count[i].size(); k++)
        {
            res.push_back(count[i][k]);
        }
    }

    return res;
    }
};