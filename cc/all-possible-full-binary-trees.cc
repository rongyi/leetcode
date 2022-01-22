// http://leetcode.com/problems/all-possible-full-binary-trees/description/
#include "xxx.hpp"

class Solution {
public:
  vector<TreeNode *> allPossibleFBT(int N) {
    // no way!
    if (N % 2 == 0 || N < 0) {
      return {};
    }
    // 仅有一个节点的情况
    if (N == 1) {
      return {new TreeNode(0)};
    }
    vector<TreeNode *> ret;

    // 左子树这么多节点
    for (int l = 1; l <= N - 2; l += 2) {
      // 右子树还剩下这么多
      int r = N - 1 - l;
      // 各自递归产生一个子树列表，然后对每一种组合
      // 凑在一起就产生一种新的树
      for (auto left : allPossibleFBT(l)) {
        for (auto right : allPossibleFBT(r)) {
          TreeNode *root = new TreeNode(0);
          root->left = left;
          root->right = right;
          ret.push_back(root);
        }
      }
    }

    return ret;
  }
};
