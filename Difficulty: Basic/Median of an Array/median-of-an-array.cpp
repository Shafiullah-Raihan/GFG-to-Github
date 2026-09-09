class Solution {
  public:
    double findMedian(vector<int> &arr) {
        // code here.
        int n= arr.size();
        sort(arr.begin(),arr.end());
        double ans =1.0;
        if(n%2==1)
        {
            ans = (1.0*arr[n/2]);
        }
        else{
            ans = ((1.0 * arr[n/2-1]) + (1.0 * arr[n/2]))/2;
        }
        return ans;
    }
};