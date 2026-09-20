/* Structure of binary tree Node
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool areAnagrams(Node *root1, Node *root2) {

        // If both trees are empty, they are anagrams.
        // If only one is empty, they cannot be anagrams.
        if (root1 == nullptr || root2 == nullptr)
            return root1 == root2;

        // Use separate queues to traverse both trees level by level.
        queue<Node *> q1;
        queue<Node *> q2;

        q1.push(root1);
        q2.push(root2);

        while (!q1.empty() && !q2.empty()) {
            // Get the number of nodes at the current level.
            int n1 = q1.size();
            int n2 = q2.size();

            // Corresponding levels must contain the same number of nodes.
            if (n1 != n2)
                return false;

            // Store the frequency difference between the two levels.
            unordered_map<int, int> freq;

            // Process the current level of both trees.
            for (int i = 0; i < n1; i++) {
                Node *node1 = q1.front();
                Node *node2 = q2.front();

                q1.pop();
                q2.pop();

                // Increase frequency for values from the first tree
                // and decrease it for values from the second tree.
                freq[node1->data]++;
                freq[node2->data]--;

                // Add children for processing the next level.
                if (node1->left != nullptr)
                    q1.push(node1->left);

                if (node1->right != nullptr)
                    q1.push(node1->right);

                if (node2->left != nullptr)
                    q2.push(node2->left);

                if (node2->right != nullptr)
                    q2.push(node2->right);
            }

            // Every frequency must be zero if the levels are anagrams.
            for (const auto &entry : freq) {
                if (entry.second != 0)
                    return false;
            }
        }

        // All corresponding levels matched.
        return q1.empty() && q2.empty();
    }
};