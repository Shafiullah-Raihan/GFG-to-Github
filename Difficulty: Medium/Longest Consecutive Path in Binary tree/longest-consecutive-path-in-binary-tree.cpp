/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:

    void longestConsecutiveUtil(Node* root, int curLength, int expected, int& res) {
        if (root == NULL)
            return;


        if (root->data == expected)
            curLength++;
        else
            curLength = 1;

       
        res = max(res, curLength);

      
        longestConsecutiveUtil(root->left, curLength, root->data + 1, res);
        longestConsecutiveUtil(root->right, curLength, root->data + 1, res);
    }

   
    int longestConsecutive(Node* root) {
        if (root == NULL)
            return -1;

        int res = 0; 

       
        longestConsecutiveUtil(root, 0, root->data, res);

       
        if (res <= 1)
            return -1;

        return res;
    }
};