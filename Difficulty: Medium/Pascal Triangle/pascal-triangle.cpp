
#define ll long long
class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        vector<vector<int>> mat(n);
        vector<ll>ans(n);
        int idx=0;
        for(ll i=0;i<n;i++)
        {
            mat[i].resize(i+1);
            for(ll j=0;j<=i;j++)
            {
                if( j==0 || j==i)
                {
                    mat[i][j] =1;
                }
                else{
                    mat[i][j] = mat[i-1][j-1] + mat[i-1][j];
                     
                }
    
            }
           
        }
        
        return mat[n-1];
    }
};


