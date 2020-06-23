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

private:
  // 分清楚递归的层次，从一个节点开始之后的比较是严格比较，一旦比较失败那么追溯到上面就是那个顶点开始不在上面
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
