// Function to compute gcd using Euclidean Algorithm
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to compute lcm using gcd
// Using (a / gcd) * b to avoid overflow
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

class SegmentTree {
  private:
    vector<long long> tree;
    vector<long long> arr;
    int n;

  public:
    SegmentTree(vector<int> input) {
        n = input.size();
        arr.assign(input.begin(), input.end());
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    // Build the segment tree
    void build(int node, int start, int end) {
        // Leaf node
        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;

        // Build left and right subtree
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);

        // Merge step: store LCM of children
        tree[node] = lcm(tree[2 * node], tree[2 * node + 1]);
    }

    // Update value at index idx to val
    void update(int node, int start, int end, int idx, long long val) {
        // Leaf node
        if (start == end) {
            arr[idx] = val;
            tree[node] = val;
            return;
        }

        // find mid
        int mid = (start + end) / 2;

        // Recurse to correct side
        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);

        // Update current node after child update
        tree[node] = lcm(tree[2 * node], tree[2 * node + 1]);
    }

    // Query LCM in range [l, r]
    long long query(int node, int start, int end, int l, int r) {
        // Completely outside range
        // Return 1 (identity for LCM)
        if (end < l || start > r)
            return 1;

        // Completely inside range
        if (l <= start && end <= r)
            return tree[node];

        // Partial overlap
        int mid = (start + end) / 2;

        long long left = query(2 * node, start, mid, l, r);
        long long right = query(2 * node + 1, mid + 1, end, l, r);

        return lcm(left, right);
    }
};

class Solution {
  public:
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {
        SegmentTree st(arr);

        vector<long long> result;

        for (auto &q : queries) {
            int type = q[0];

            if (type == 1) {
                int idx = q[1];
                int val = q[2];

                // Perform update
                st.update(1, 0, arr.size() - 1, idx, val);
            } else {
                int l = q[1];
                int r = q[2];

                // Perform query
                long long ans = st.query(1, 0, arr.size() - 1, l, r);
                result.push_back(ans);
            }
        }

        return result;
    }
};