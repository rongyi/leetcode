// http://leetcode.com/problems/diameter-of-binary-tree/description/
#include "xxx.h"

class Solution {
public:
  int diameterOfBinaryTree(TreeNode *root) {
    unordered_map<TreeNode *, int> cache;
    // 产生每一个节点的高度
    height(root, cache);
    int ret = 0;
    dfs(root, cache, ret);
    return ret;
  }

private:
  void dfs(TreeNode *root, unordered_map<TreeNode *, int> &cache, int &ret) {
    if (!root) {
      return;
    }
    int cur = 0;
    if (root->left) {
      cur += cache[root->left];
    }
    if (root->right) {
      cur += cache[root->right];
    }
    ret = max(ret, cur);

    dfs(root->left, cache, ret);
    dfs(root->right, cache, ret);
  }
  int height(TreeNode *root, unordered_map<TreeNode *, int> &cache) {
    if (!root) {
      return 0;
    }
    if (cache.find(root) != cache.end()) {
      return cache[root];
    }
    auto l = height(root->left, cache);
    auto r = height(root->right, cache);
    auto ret = max(l, r) + 1;

    cache[root] = ret;
    return ret;
  }
};
