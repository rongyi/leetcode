// http://leetcode.com/problems/linked-list-in-binary-tree/description/
#include "xxx.h"

class Solution {
public:
  bool isSubPath(ListNode *head, TreeNode *root) {
    if (!root) {
      return false;
    }
    // 要么从root开始就是，要么就是从左子树开始或者是右子树开始就是
    return check(head, root) || isSubPath(head, root->left) ||
           isSubPath(head, root->right);
  }
  bool check(ListNode *head, TreeNode *root) {
    if (!head) {
      return true;
    }

    if (!root) {
      return false;
    }

    return (root->val == head->val) &&
           (check(head->next, root->left) || check(head->next, root->right));
  }
};
