// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/
#include "xxx.hpp"

class Solution {
public:
  long long kthLargestLevelSum(TreeNode *root, int k) {
    vector<long long> lsum;
    dfs(root, lsum, 1);
    if (lsum.size() < k) {
      return -1;
    }
    nth_element(lsum.begin(), lsum.begin() + k - 1, lsum.end(), greater<>());

    return lsum[k - 1];
  }

private:
  void dfs(TreeNode *cur, vector<long long> &lsum, int cur_level) {
    if (!cur) {
      return;
    }
    if (cur_level > lsum.size()) {
      lsum.push_back(0ll);
    }
    lsum[cur_level - 1] += cur->val;

    dfs(cur->left, lsum, cur_level + 1);
    dfs(cur->right, lsum, cur_level + 1);
  }
};

