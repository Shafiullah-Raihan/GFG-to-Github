
class Solution {
  public:
    bool isBalanced(string& s) {
       stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        
        // Check if the character is an opening bracket
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]); 
        } 
      
        else {

 
            if (!st.empty() && 
                ((st.top() == '(' && s[i] == ')') ||
                 (st.top() == '{' && s[i] == '}') ||
                 (st.top() == '[' && s[i] == ']'))) {

                st.pop(); 
            }
            else {
                
                return false; 
            }
        }
    }
    
    return st.empty();
    }
};
