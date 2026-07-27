/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:

    Node* buildTree(vector<int>& pre, vector<int>& preMirror, int& preIndex, int left, int right, unordered_map<int, int>& mp, int n) {

        if (preIndex >= n || left > right)
            return NULL;

        Node* root = new Node(pre[preIndex++]);

        if (left == right)
            return root;

        int mirrorIndex = mp[pre[preIndex]];

        if (mirrorIndex >= left && mirrorIndex <= right) {

            root->left = buildTree(pre, preMirror, preIndex, mirrorIndex, right, mp, n);

            root->right =
                buildTree(pre, preMirror, preIndex, left + 1, mirrorIndex - 1, mp, n);
        }

        return root;
    }

    Node* constructBinaryTree(vector<int>& pre, vector<int>& preMirror) {

        int n = pre.size();

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[preMirror[i]] = i;
        }

        int preIndex = 0;

        return buildTree(pre, preMirror, preIndex, 0, n - 1, mp, n);
    }
};