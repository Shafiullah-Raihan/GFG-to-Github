class Solution {
  public:
    vector<int> quadraticRoots(int a, int b, int c) {
        // code here
        int d = b*b - 4*a*c;
        if(d<0) return {-1};
        int x1 = floor((-b + sqrt(d)) / (2.0 * a));
        int x2 = floor((-b - sqrt(d)) / (2.0 * a));
        return {x1,x2};
    }
};