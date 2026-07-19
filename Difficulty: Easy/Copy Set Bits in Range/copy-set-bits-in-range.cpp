class Solution {
  public:
    int setSetBit(int x, int y, int l, int r) {
        // code here
         int m = x;
        for(int i = l;i <= r;i++){
            if(y & (1 << (i-1) ) )
                m |= (1 << (i-1));
        }
        return m;
    }
};