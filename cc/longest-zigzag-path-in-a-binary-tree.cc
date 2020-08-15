// http://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/
#include "xxx.h"

class Solution {
public:
  int longestZigZag(TreeNode *root) {
    return max(dfs(root, true, -1), dfs(root, false, -1));
  }

private:
  int dfs(TreeNode *node, bool to_left, int depth) {
    if (!node) {
      return depth;
    }
    // 按照上级的意思走
    int follow = dfs(to_left ? node->left : node->right, !to_left, depth + 1);
    // 自己独立把没走的那个分之走一下，“上级”要我往左，那我就把剩下的往右自己走一遍，要求下级方向和当前的指挥方向相同
    //     x
    //    / \
    //   b   c
    //    \ /
    // 上级要我往b走，则自己把c这个分之走完，下一步的方向如上，另外一个case下一步方向如上，可以看到和上级的命令方向相同
    int fork = dfs(to_left ? node->right : node->left, to_left, 0);

    return max(follow, fork);
  }

private:
  int longestZigZagTLE(TreeNode *root) {
    int ret = 0;
    preorder(root, ret);
    return ret;
  }

  void preorder(TreeNode *node, int &ret) {
    if (!node) {
      return;
    }
    int left_count = 0;
    int right_count = 0;
    zigzag(node, true, left_count);
    zigzag(node, false, right_count);
    ret = max(ret, max(left_count, right_count));

    preorder(node->left, ret);
    preorder(node->right, ret);
  }
  void zigzag(TreeNode *node, bool toleft, int &count) {
    if (!node) {
      return;
    }
    if (toleft && node->left) {
      ++count;
      zigzag(node->left, !toleft, count);

      return;
    }
    if (!toleft && node->right) {
      zigzag(node->right, !toleft, count);
      ++count;
    }
  }
};
