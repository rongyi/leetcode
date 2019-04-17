// http://leetcode.com/problems/maximum-binary-tree/description/
#include "xxx.h"

class Solution {
public:
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    return doMkMaxTree(nums, 0, nums.size() - 1);
  }
  TreeNode *doMkMaxTree(vector<int> &nums, int start, int end) {
    if (start > end) {
      return nullptr;
    }
    if (start == end) {
      return new TreeNode(nums[start]);
    }
    // no need to use pq
    int m = numeric_limits<int>::min();
    int idx = -1;
    for (int i = start; i <= end; i++) {
      m = max(m, nums[i]);
      if (m == nums[i]) {
        idx = i;
      }
    }
    TreeNode *root = new TreeNode(m);
    // 全在右子树
    if (idx == start) {
      root->right = doMkMaxTree(nums, start + 1, end);
    } else if (idx == end) {
      // 全在左子树
      root->left = doMkMaxTree(nums, start, end - 1);
    } else {
      // 劈开
      root->left = doMkMaxTree(nums, start, idx - 1);
      root->right = doMkMaxTree(nums, idx + 1, end);
    }
    return root;
  }
};
