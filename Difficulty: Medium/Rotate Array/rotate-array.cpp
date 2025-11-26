class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n=arr.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            ans[i]= arr[(i+d)%n];
        }
        arr=ans;
    }
};