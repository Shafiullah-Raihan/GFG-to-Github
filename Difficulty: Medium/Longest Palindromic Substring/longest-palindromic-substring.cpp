class Solution {
  public:
    string getLongestPal(string &s) {
        // code here
        int n= s.size();
        int idx = -1;
        int ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            int start = i,end=i;
            // int maxLen =0;
            while(start>=0 && end<n && s[start] == s[end])
            {
                if(end-start+1>ans)
                {
                    ans = max(ans, end-start+1);
                    idx = start;
                }
                start--,end++;
                
                
            }
            start = i,end = i+1;
            while(start>=0 && end<n && s[start] == s[end])
            {
                if(end-start+1>ans)
                {
                    ans = max(ans, end-start+1);
                    idx = start;
                }
                start--,end++;
            }
            // ans = max(maxLen,ans);
        }
        return s.substr(idx,ans);
    }
};