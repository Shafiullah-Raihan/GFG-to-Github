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
}; */

class Solution {
public:

    int maxDiffUtil(Node *t, int *res)
    {
        if (t == nullptr)
            return INT_MAX;

  
        if (t->left == nullptr && t->right == nullptr)
            return t->data;

        int leftMin = maxDiffUtil(t->left, res);
        int rightMin = maxDiffUtil(t->right, res);

        int val = min(leftMin, rightMin);

        *res = max(*res, t->data - val);

        return min(t->data, val);
    }

    int maxDiff(Node *root)
    {
        int res = INT_MIN;

        maxDiffUtil(root, &res);

        return res;
    }
};