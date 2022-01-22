// http://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
#include "xxx.hpp"

class Solution {
public:
  int goodNodes(TreeNode *root) {
    int ret = 0;

    recur(root, numeric_limits<int>::min(), ret);

    return ret;
  }

private:
  void recur(TreeNode *root, int path_max, int &good_nums) {
    if (!root) {
      return;
    }
    if (path_max <= root->val) {
      good_nums++;
    }

    recur(root->left, max(path_max, root->val), good_nums);
    recur(root->right, max(path_max, root->val), good_nums);
  }
};
