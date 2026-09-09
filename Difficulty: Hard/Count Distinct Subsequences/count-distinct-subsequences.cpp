#define ll long long
const ll mod = 1e9+7;

class Solution {
  public:
    int distinctSubseq(string &str) {
        // code here
        int n = str.size();
        vector<ll>dp(n+1);
        
        vector<ll>c(26,-1);
        
        dp[0] =1;
        
        for(ll i=1;i<=n;i++)
        {
            dp[i] = (2*dp[i-1])%mod;
            if(c[str[i-1]-'a'] != -1)
            {
                dp[i] = (dp[i] - dp[c[str[i-1]-'a']]+ mod)%mod;
            }
            c[str[i-1]-'a'] =i -1;
        }
        return (int)dp[n]%mod;
    }
};