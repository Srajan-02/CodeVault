struct Node {
    int max_len;
    int pref_len;
    int suff_len;
    char left_char;
    char right_char;
    int size;
};

class Solution {
private:
    vector<Node> tree;

    Node merge(const Node& left, const Node& right) {
        Node parent;
        parent.size = left.size + right.size;
        parent.left_char = left.left_char;
        parent.right_char = right.right_char;
        parent.pref_len = left.pref_len;
        parent.suff_len = right.suff_len;
        parent.max_len = max(left.max_len, right.max_len);

        if (left.right_char == right.left_char) {
            parent.max_len = max(parent.max_len, left.suff_len + right.pref_len);
            if (left.pref_len == left.size) {
                parent.pref_len = left.size + right.pref_len;
            }
            if (right.suff_len == right.size) {
                parent.suff_len = right.size + left.suff_len;
            }
        }
        return parent;
    }

    void build(int node, int start, int end, const string& s) {
        if (start == end) {
            tree[node] = {1, 1, 1, s[start], s[start], 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, s);
        build(2 * node + 1, mid + 1, end, s);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, char val) {
        if (start == end) {
            tree[node] = {1, 1, 1, val, val, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int m = s.size();
        int n = queryIndices.size();
        
        tree.resize(4 * m);
        build(1, 0, m - 1, s);

        vector<int> res;
        res.reserve(n);

        for (int i = 0; i < n; ++i) {
            update(1, 0, m - 1, queryIndices[i], queryCharacters[i]);
            res.push_back(tree[1].max_len);
        }

        return res;
    }
};