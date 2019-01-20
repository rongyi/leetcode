// http://leetcode.com/problems/add-two-numbers-ii/description/
#include "xxx.h"

class Solution {
public:
  // 1.转换成int行不通，过不了大数
  // 2. 翻转list吧把问题转化为第一种解答
  // 3. 把数放在vector里，然后相加
  ListNode *addTwoNumbersReverse(ListNode *l1, ListNode *l2) {
    l1 = reverseList(l1);
    l2 = reverseList(l2);

    int carry = 0;
    auto p1 = l1;
    auto p2 = l2;
    ListNode *ret = nullptr;
    ListNode *cur = nullptr;
    while (p1 && p2) {
      auto sum = p1->val + p2->val + carry;
      carry = sum / 10;
      sum %= 10;
      ListNode *new_node = new ListNode(sum);
      if (cur == nullptr) {
        cur = new_node;
        ret = cur;
      } else {
        cur->next = new_node;
        cur = cur->next;
      }
      p1 = p1->next;
      p2 = p2->next;
    }
    // only one will be exec
    while (p1) {
      auto sum = p1->val + carry;
      carry = sum / 10;
      sum %= 10;
      ListNode *new_node = new ListNode(sum);
      cur->next = new_node;
      cur = cur->next;
      p1 = p1->next;
    }

    while (p2) {
      auto sum = p2->val + carry;
      carry = sum / 10;
      sum %= 10;
      ListNode *new_node = new ListNode(sum);
      cur->next = new_node;
      cur = cur->next;
      p2 = p2->next;
    }
    if (carry > 0) {
      ListNode *new_node = new ListNode(carry);
      cur->next = new_node;
      cur = cur->next;
    }
    return reverseList(ret);
  }

  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    vector<int> i1;
    vector<int> i2;

    auto push = [](ListNode *l, vector<int> &ret) {
      while (l) {
        ret.push_back(l->val);
        l = l->next;
      }
    };
    push(l1, i1);
    push(l2, i2);

    const int m = i1.size();
    const int n = i2.size();
    ListNode *head = nullptr;
    // ListNode *cur = nullptr;
    int carry = 0;

    for (int i = m - 1, j = n - 1; i >= 0 || j >= 0 || carry; i--, j--) {
      int sum = carry;
      if (i >= 0) {
        sum += i1[i];
      }
      if (j >= 0) {
        sum += i2[j];
      }
      carry = sum / 10;
      ListNode *fresh = new ListNode(sum % 10);
      // 倒着走
      fresh->next = head;
      head = fresh;
    }

    return head;
  }

private:
  ListNode *reverseList(ListNode *head) {
    ListNode dummy(-1);
    ListNode *cur = &dummy;
    while (head) {
      auto tmp = head->next;
      head->next = cur->next;
      cur->next = head;

      head = tmp;
    }
    return dummy.next;
  }
};
