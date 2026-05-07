class Solution {
  public:
    
    bool isValidString(string s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                cnt++;
            else if (s[i] == ')')
                cnt--;
            if (cnt < 0)
                return false;
        }
        return (cnt == 0);
    }

    
    vector<string> validParenthesis(string &s) {

       
        unordered_map<string, int> visit;

      
        queue<string> q;

       
        vector<string> res;
        bool level = false;

        
        q.push(s);

        visit[s] = 1;

        while (!q.empty()) {
            string temp = q.front();
            q.pop();

            if (isValidString(temp)) {

                res.push_back(temp);

                
                level = true;
            }

            if (level)
                continue;

            for (int i = 0; i < temp.length(); i++) {

                
                if (temp[i] != '(' && temp[i] != ')')
                    continue;

                
                string cur = temp.substr(0, i) + temp.substr(i + 1);

                if (visit.count(cur) == 0) {
                    q.push(cur);
                    visit[cur] = 1;
                }
            }
        }
        return res;
    }
};