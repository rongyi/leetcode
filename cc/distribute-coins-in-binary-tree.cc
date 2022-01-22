// http://leetcode.com/problems/distribute-coins-in-binary-tree/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/distribute-coins-in-binary-tree/discuss/221939/C%2B%2B-with-picture-post-order-traversal
  int distributeCoins(TreeNode *root) {
    int ret = 0;
    dfs(root, ret);

    return ret;
  }
  // 我要平衡，需要吐出来多少，或者需要被人给我多少？
  int dfs(TreeNode *root, int &mv) {
    if (!root) {
      return 0;
    }
    auto l = dfs(root->left, mv);
    auto r = dfs(root->right, mv);
    mv += abs(l) + abs(r);

    // 算根节点的时候，统筹一下，看看自己手里有多少，另外
    // 两个子树各自需要多少或者吐多少，然后自己再消耗一个coin
    return root->val + l + r - 1;
  }
};
