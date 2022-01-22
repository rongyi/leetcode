// http://leetcode.com/problems/linked-list-random-node/description/
#include "xxx.hpp"

class Solution {
public:
  /** @param head The linked list's head.
    Note that the head is guaranteed to be not null, so it contains at least
    one node. */
  Solution(ListNode *head) : len_(0) {
    list_ = head;
    auto *p = head;
    while (p) {
      len_++;
      p = p->next;
    }
    gen_.seed(std::random_device()());
    dist_ = uniform_int_distribution<int>(0, len_ - 1);
  }

  /** Returns a random node's value. */
  int getRandom() {
    auto index = dist_(gen_);
    auto *p = list_;
    for (int i = 0; i < index; i++) {
      p = p->next;
    }
    return p->val;
  }

private:
  int len_;
  uniform_int_distribution<int> dist_;
  std::mt19937 gen_;
  ListNode *list_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
