// https://leetcode.com/problems/reverse-nodes-in-even-length-group/
#include "xxx.hpp"

class Solution {
public:
  ListNode *reverseEvenLengthGroups(ListNode *head) {
    ListNode dummy(-1);
    dummy.next = head;
    // header pointer for prev chunk
    ListNode *prev = &dummy;

    for (int len = 1; len < 1e5 && head; len++) {
      ListNode *cur_chunk_tail = head;
      ListNode *next_chunk_head = nullptr;
      int j = 1;
      // len is the expected chunk size
      // j is the *real* chunk size
      while (j < len && cur_chunk_tail && cur_chunk_tail->next) {
        cur_chunk_tail = cur_chunk_tail->next;
        j++;
      }
      next_chunk_head = cur_chunk_tail->next;
      // j + 1 is the *real* length
      if ((j % 2) == 0) {
        // break the link list!
        cur_chunk_tail->next = nullptr;
        prev->next = rev(head);
        prev = head;
        head->next = next_chunk_head;
        head = next_chunk_head;
      } else {
        prev = cur_chunk_tail;
        head = next_chunk_head;
      }
    }

    return dummy.next;
  }

private:
  ListNode *rev(ListNode *head) {
    if (!head) {
      return nullptr;
    }
    ListNode *prev = nullptr;
    while (head) {
      ListNode *save = head->next;
      head->next = prev;
      prev = head;
      head = save;
    }

    return prev;
  }
};

int main() {
  ListNode n5(5), n2(2), n6(6), n3(3), n9(9), n1(1), n7(3), n32(3), n8(8),
      n4(4);
  n5.next = &n2;
  n2.next = &n6;
  n6.next = &n3;
  n3.next = &n9;
  n9.next = &n1;
  n1.next = &n7;
  n7.next = &n32;
  n32.next = &n8;
  n8.next = &n4;
  Solution so;
  so.reverseEvenLengthGroups(&n5);
}
