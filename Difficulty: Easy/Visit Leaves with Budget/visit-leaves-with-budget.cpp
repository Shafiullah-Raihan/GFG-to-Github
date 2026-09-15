/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int getCount(Node *root, int k) {
        if (!root)
            return 0;

        queue<Node *> q;
        q.push(root);

        int level = 1;
        int cnt = 0;

        // Perform level order traversal
        while (!q.empty()) {

            int size = q.size();
            int leafCount = 0;

            // Process all nodes at current level
            for (int i = 0; i < size; i++) {

                Node *curr = q.front();
                q.pop();

                // Count leaf nodes
                if (!curr->left && !curr->right)
                    leafCount++;

                // Add children for next level
                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }

            // Find how many leaves can be visited
            int canVisit = k / level;

            int take = min(leafCount, canVisit);

            // Update answer and remaining budget
            cnt += take;
            k -= take * level;

            // No leaf at this or later level can be visited
            if (k < level)
                break;

            level++;
        }

        return cnt;
    }
};