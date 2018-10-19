// http://leetcode.com/problems/sort-list/description/
#include "one.h"

class Solution {
public:
  // 这个就是上面插入排序的方法，但是绝大部分的提交都比这个快
  ListNode *sortListV1(ListNode *head) {
    if (!head) {
      return nullptr;
    }

    ListNode dummy(-1);
    ListNode *cur = &dummy;
    auto *p = head;
    while (p) {
      auto *next = p->next;
      cur = &dummy;
      while (cur->next && cur->next->val < p->val) {
        cur = cur->next;
      }
      // chain together
      p->next = cur->next;
      cur->next = p;

      p = next;
    }

    return dummy.next;
  }

  ListNode *sortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    // unchain
    fast = slow->next;
    slow->next = nullptr;

    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(fast);

    return merge(l1, l2);
  }

private:
  ListNode *merge(ListNode *l1, ListNode *l2) {
    if (!l1) {
      return l2;
    } else if (!l2) {
      return l1;
    } else if (!l1 && !l2) {
      return nullptr;
    }

    ListNode dummy(-1);
    ListNode *p = &dummy;

    while (l1 && l2) {
      if (l1->val < l2->val) {
        p->next = l1;
        l1 = l1->next;
      } else {
        p->next = l2;
        l2 = l2->next;
      }
      p = p->next;
    }
    if (l1) {
      p->next = l1;
    } else if (l2) {
      p->next = l2;
    }
    return dummy.next;
  }
};
