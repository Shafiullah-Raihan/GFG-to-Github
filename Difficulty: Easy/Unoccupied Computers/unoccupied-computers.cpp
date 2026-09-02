class Solution {
public:
    int solve(int n, string s) {
        map<char,int> mp;
        set<char> st;

        for(auto u : s)
        {
            
            if(st.count(u))
                continue;

            if(mp.size() < n || mp.count(u))
            {
                mp[u]++;

                if(mp[u] % 2 == 0)
                {
                    mp.erase(u);
                }
            }
            else
            {
                st.insert(u);
            }
        }

        return st.size();
    }
};