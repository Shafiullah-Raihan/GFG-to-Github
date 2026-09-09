class Solution {
  public:
    int digitsum(int x)
    {
        int rem=0,sum=0;
        while(x>0)
        {
            sum += (x%10);
            x/=10;
        }
        return sum;
    }
    int findMax(int n) {
        // code Here
        string s = to_string(n);
        int bestsum=digitsum(n);
        int sum=0,ans=n;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '0') continue;
            string temp=s;
            temp[i]--;
            for(int j=i+1;j<s.size();j++)
            {
                temp[j] = '9';
            }
            int candidate = stoi(temp);
            int newsum = digitsum(stoi(temp));
            if(newsum>bestsum || (candidate>ans && newsum == bestsum))
            {
                bestsum = newsum;ans = candidate;
            }
        }
        return ans;
        
        
        
    }
};
