// http://leetcode.com/problems/copy-list-with-random-pointer/description/
#include "xxx.hpp"

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};
class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    if (!head) {
      return nullptr;
    }
    auto *p = head;
    // 分配的也都串在一起，这样就能把random也给算出来
    while (p) {
      auto *next = p->next;
      // 分配并串在一起
      RandomListNode *new_node = new RandomListNode(p->label);
      new_node->next = next;
      p->next = new_node;

      p = next;
    }
    RandomListNode dummy(-1);
    RandomListNode *cur = &dummy;
    p = head;
    // 要先串起来random然后再split，因为有可能后面的random指到前面来呀
    while (p) {
      if (p->random) {
        p->next->random = p->random->next;
      }
      p = p->next->next;
    }

    p = head;
    while (p) {
      auto *next = p->next->next;

      // split
      cur->next = p->next;
      cur = cur->next;
      // omit the malloc node
      p->next = next;

      p = next;
    }

    return dummy.next;
  }
};
