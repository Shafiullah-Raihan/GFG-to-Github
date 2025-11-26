class Solution {
  public:
    int thirdLargest(vector<int> &arr) {
        // Your code here
        sort(arr.rbegin(),arr.rend());
        ///arr.erase(unique(arr.begin(),arr.end()),arr.end());
        int n=arr.size();
        if(arr.size()<3) return -1;
        return arr[2];
        
    }
};