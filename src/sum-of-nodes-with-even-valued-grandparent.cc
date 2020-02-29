// http://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/description/
#include "xxx.h"

class Solution {
public:
  int sumEvenGrandparent(TreeNode *root) {
    int ret = 0;

    recur(root, false, ret);

    // ignore one level, so we start the second level as well
    // so we collect all the level at last
    recur(root->left, false, ret);
    recur(root->right, false, ret);

    return ret;
  }

private:
  void recur(TreeNode *cur, bool ge /*grandparent is even?*/, int &sum) {
    if (!cur) {
      return;
    }
    if (ge) {
      sum += cur->val;
    }

    if (cur->left) {
      // cur is even, then collect its grand child
      if (cur->val % 2 == 0) {
        recur(cur->left->left, true, sum);
        recur(cur->left->right, true, sum);
      } else {
        recur(cur->left->left, false, sum);
        recur(cur->left->right, false, sum);
      }
    }
    if (cur->right) {
      // cur is even, then collect its grand child
      if (cur->val % 2 == 0) {
        recur(cur->right->left, true, sum);
        recur(cur->right->right, true, sum);
      } else {
        recur(cur->right->left, false, sum);
        recur(cur->right->right, false, sum);
      }
    }
  }
};

int main() {}
