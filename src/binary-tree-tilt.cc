// http://leetcode.com/problems/binary-tree-tilt/description/
#include "xxx.h"

class Solution {
public:
  int findTilt(TreeNode *root) {
    if (!root) {
      return 0;
    }
    unordered_map<TreeNode *, int> cache;
    // 问题的关键在于算sum，分开算，这样清晰一点
    gensum(root, cache);

    int sum = 0;
    calculate_tilt(root, cache, sum);

    return sum;
  }

private:
  void calculate_tilt(TreeNode *root, unordered_map<TreeNode *, int> &cache,
                      int &sum) {
    if (!root) {
      return;
    }
    if (root->left && root->right) {
      sum += abs(cache[root->left] - cache[root->right]);
      calculate_tilt(root->left, cache, sum);
      calculate_tilt(root->right, cache, sum);
    } else if (root->left) {
      sum += abs(cache[root->left]);
      calculate_tilt(root->left, cache, sum);
    } else if (root->right) {
      sum += abs(cache[root->right]);
      calculate_tilt(root->right, cache, sum);
    }
  }

  int gensum(TreeNode *root, unordered_map<TreeNode *, int> &cache) {
    if (!root) {
      return 0;
    }
    if (cache.find(root) != cache.end()) {
      return cache[root];
    }
    auto l = gensum(root->left, cache);
    auto r = gensum(root->right, cache);
    auto sum = root->val + l + r;
    cache[root] = sum;

    return sum;
  }
};
