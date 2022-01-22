// http://leetcode.com/problems/merge-two-binary-trees/description/
#include "xxx.hpp"

class Solution {
public:
  TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
    if (!t1) {
      return t2;
    }
    if (!t2) {
      return t1;
    }
    TreeNode dummy(-1);
    TreeNode *d = &dummy;
    // 默认根节点挂在dummy的左侧
    recur(t1, t2, d, true);

    return d->left;
  }

private:
  // parent比当前 t1 t2要高一级，然后通过一个标记为is_left来标记串在左边还是右边
  void recur(TreeNode *t1, TreeNode *t2, TreeNode *&parent, bool is_left) {
    bool has_t1 = !!t1;
    bool has_t2 = !!t2;
    if (!has_t1 && !has_t2) {
      return;
    }
    int val = 0;
    if (has_t1) {
      val += t1->val;
    }
    if (has_t2) {
      val += t2->val;
    }
    TreeNode *node = new TreeNode(val);
    // cout << node->val << endl;
    if (is_left) {
      parent->left = node;
    } else {
      parent->right = node;
    }
    // 新创建节点node此时为下一层节点的parent，往左走就串在左边，往右走就串在右边
    recur(has_t1 ? t1->left : nullptr, has_t2 ? t2->left : nullptr, node, true);
    recur(has_t1 ? t1->right : nullptr, has_t2 ? t2->right : nullptr, node,
          false);
  }
};
