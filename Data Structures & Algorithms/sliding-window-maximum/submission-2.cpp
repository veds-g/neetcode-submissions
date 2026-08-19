#include <bits/stdc++.h>
class SegmentTree {
    int n;
    vector<int> tree;
public:
    SegmentTree(vector<int>& data) {
        n = data.size();
        if (n > 0) {
            tree.resize(4 * n, 0);
            buildTree(0, 0, n - 1, data);
        }
    }

    void buildTree(int treeIdx, int left, int right, vector<int>& data) {
        if (left == right) {
            tree[treeIdx] = data[left];
            return;
        }

        int mid = left + (right - left) / 2;
        int leftChild = 2 * treeIdx + 1;
        int rightChild = 2 * treeIdx + 2;
        buildTree(leftChild, left, mid, data);
        buildTree(rightChild, mid + 1, right, data);

        tree[treeIdx] = max(tree[leftChild], tree[rightChild]);
    }

    int query(int treeIdx, int left, int right, int l, int r) {
        if (r < left || l > right) {
            return INT_MIN;
        }

        if (l <= left and right <= r) {
            return tree[treeIdx];
        }

        int mid = left + (right - left) / 2;
        int leftChild = treeIdx * 2 + 1;
        int rightChild = treeIdx * 2 + 2;

        return max(query(leftChild, left, mid, l, r), query(rightChild, mid + 1, right, l, r));
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        SegmentTree st(nums);
        int n = nums.size();

        vector<int> ans;
        for (int i = 0; i <= n - k; i++) {
            ans.push_back(st.query(0, 0, n - 1, i, i + k - 1));
        }

        return ans;
    }
};
