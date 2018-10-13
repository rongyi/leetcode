// http://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
#include "one.h"

class Solution {
public:
  TreeNode *sortedListToBST(ListNode *head) {
    int len = 0;
    auto *p = head;
    while (p) {
      len++;
      p = p->next;
    }

    return construct(head, 0, len - 1);
  }

private:
  TreeNode *construct(ListNode *&list, int start, int end) {
    if (start > end) {
      return nullptr;
    }
    auto mid = start + (end - start) / 2;
    TreeNode *left_child = construct(list, start, mid - 1);
    TreeNode *parent = new TreeNode(list->val);

    parent->left = left_child;

    list = list->next;
    parent->right = construct(list, mid + 1, end);

    return parent;
  }
};
