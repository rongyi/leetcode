// http://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
#include "xxx.hpp"

class Solution {
public:
  TreeNode *sortedListToBST(ListNode *head) {
    if (!head) {
      return nullptr;
    }
    if (!head->next) {
      return new TreeNode(head->val);
    }

    ListNode *slow = head;
    ListNode *fast = slow->next;
    while (fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    ListNode *mid = slow->next;
    slow->next = nullptr;

    TreeNode *ret = new TreeNode(mid->val);
    ret->left = sortedListToBST(head);
    ret->right = sortedListToBST(mid->next);

    return ret;
  }
};
