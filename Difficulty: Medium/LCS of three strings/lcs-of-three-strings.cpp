class Solution {
  public:
  int dp[101][101][101];
    int raihan(string& s1,string& s2,string& s3,int a,int b,int c)
    {
        if(a<=0 || b<=0 || c<=0) return 0;
        
        if(dp[a][b][c] != -1) return dp[a][b][c];
        
        if((s1[a-1] == s2[b-1]) && s2[b-1] == s3[c-1])
        {
            dp[a][b][c] = 1 + raihan(s1,s2,s3,a-1,b-1,c-1);
        }
        else{
            dp[a][b][c] = max({raihan(s1,s2,s3,a-1,b,c),raihan(s1,s2,s3,a,b-1,c), raihan(s1,s2,s3,a,b,c-1)});
        }
        return dp[a][b][c];
    }
    int lcsOf3(string& s1, string& s2, string& s3) {
        // Code here
        int a=s1.size(),b=s2.size(),c=s3.size();
        memset(dp,-1,sizeof(dp));
        int ans=raihan(s1,s2,s3,a,b,c);
        return ans;
    }
};
