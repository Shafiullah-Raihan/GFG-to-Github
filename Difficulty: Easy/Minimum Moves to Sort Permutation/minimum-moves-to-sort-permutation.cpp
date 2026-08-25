class Solution {
  public:
    int minMoves(vector<int>& arr) {
        // code here
        int n=arr.size();
        
        vector<int>lis(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(lis[arr[i]-1] != 0)
            {
                lis[arr[i]] = lis[arr[i]-1]+1;
            }
            else{
                lis[arr[i]] =1;
            }
        }
        int ans=0;
        for(int i=0;i<=n;i++)
        {
            ans = max(ans,lis[i]);
        }
        return n-ans;
        
        
        
        
        
        
        
        // int ans1=0,ans2=0,n=arr.size();
        // for(int i=1;i<arr.size();i++)
        // {
        //     if(arr[i]<arr[i-1]) ans1++;
        // }
        // for(int i=n-2;i>=0;i--)
        // {
        //     if(arr[i]>arr[i+1]) ans2++;
        // }
        // return max(ans1,ans2);
    }
};