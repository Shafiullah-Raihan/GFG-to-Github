/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/

class Solution {
  public:
    void raihan(Node* root, int& ans,int& prev)
    {
        if(root == nullptr) return ;
        
        
        // cur = root ->data;
        raihan(root->left,ans,prev);
        if(prev != -1)
        {
            ans = min(ans,abs(root->data - prev));
        }
        prev = root->data;
        
        raihan(root->right,ans,prev);
        
        
        
    }
    int absDiff(Node *root) {
        // code here
        int ans=INT_MAX;
        int prev = -1;
        raihan(root,ans,prev);
        return ans;
    }
};