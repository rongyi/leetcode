// http://leetcode.com/problems/validate-binary-search-tree/description/

#include "xxx.hpp"

class Solution {
public:
  bool isValidBST(TreeNode *root) {
    return recur(root, numeric_limits<long long>::min(),
                 numeric_limits<long long>::max());
  }

private:
  bool recur(TreeNode *cur, long long l, long long r) {
    if (!cur) {
      return true;
    }
    if (cur->val < r && cur->val > l) {
      return recur(cur->left, l, cur->val) && recur(cur->right, cur->val, r);
    }
    return false;
  }
};
