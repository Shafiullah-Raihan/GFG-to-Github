
class Solution {

  private:
    void fill_array(string s, int a[]) {
        a[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            int series = a[i - 1];
            while (series) {
                if (s[series] == s[i]) {
                    a[i] = series + 1;
                    break;
                }
                series = a[series - 1];
            }
            if (!series)
                a[i] = (s[i] == s[0]);
        }
    }

  public:
    string compress(string &s) {
        int a[(int)s.size()];

        fill_array(s, a);

        stack<char> shortened;

        for (int i = s.size() - 1; i > 0; i--)
        {
            if (i % 2 == 0) {
                shortened.push(s[i]);
                continue;
            }


            bool star_here = 0;

            int suffix = a[i];
            int substrlen = i + 1;


            if (suffix * 2 >= substrlen)
                if (substrlen % (substrlen - suffix) == 0)
                    if ((substrlen / (substrlen - suffix)) % 2 == 0)

                        star_here = 1;

            if (star_here) {
                shortened.push('*');
                i = i / 2 + 1;
            }
            else
                shortened.push(s[i]);
        }

        string ret;
        ret.push_back(s[0]);

        while (!shortened.empty()) {

            ret.push_back(shortened.top());
            shortened.pop();
        }

        return ret;
    }
};
