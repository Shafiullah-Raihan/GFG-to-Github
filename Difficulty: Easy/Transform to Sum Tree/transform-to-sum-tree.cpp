/* Structure for Tree Node
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

    int solve(Node* node) {
        if(node == NULL)
            return 0;

        int old_val = node->data;

        node->data = solve(node->left) + solve(node->right);

        return node->data + old_val;
    }

    void toSumTree(Node *node) {
        solve(node);
    }
};