class Solution {
  public:
    int andInRange(int l, int r) {
        // code here
        int ans=0;
        while(l != r)
        {
            l>>=1;
            r>>=1;
            ans++;
        }
        return (l<<ans);
        
    }
};
