// http://leetcode.com/problems/design-linked-list/description/
#include "xxx.h"

class MyLinkedList {
private:
  struct ListNode {
    int val;
    ListNode *next;
  };

public:
  /** Initialize your data structure here. */
  MyLinkedList() : dummy_{0, nullptr}, tail_{&dummy_.next} {}

  /** Get the value of the index-th node in the linked list. If the index is
   * invalid, return -1. */
  int get(int index) {
    ListNode *tmp = dummy_.next;
    while (index-- && tmp) {
      tmp = tmp->next;
    }
    return tmp ? tmp->val : -1;
  }

  /** Add a node of value val before the first element of the linked list. After
   * the insertion, the new node will be the first node of the linked list. */
  void addAtHead(int val) {
    if (tail_ == &dummy_.next) {
      addAtTail(val);
    } else {
      ListNode *tmp = new ListNode{val, dummy_.next};
      dummy_.next = tmp;
    }
  }

  /** Append a node of value val to the last element of the linked list. */
  void addAtTail(int val) {
    ListNode *tmp = new ListNode{val, nullptr};
    *tail_ = tmp;
    tail_ = &tmp->next;
  }

  /** Add a node of value val before the index-th node in the linked list. If
   * index equals to the length of linked list, the node will be appended to the
   * end of linked list. If index is greater than the length, the node will not
   * be inserted. */
  void addAtIndex(int index, int val) {
    ListNode **it = &dummy_.next;
    while (index-- && (*it)) {
      it = &(*it)->next;
    }
    if (index < 0) {
      ListNode *tmp = new ListNode{val, *it};
      *it = tmp;

      if (it == tail_) {
        tail_ = &tmp->next;
      }
    }
  }

  /** Delete the index-th node in the linked list, if the index is valid. */
  void deleteAtIndex(int index) {
    ListNode **it = &dummy_.next;

    while (index-- && (*it)) {
      it = &(*it)->next;
    }

    if (*it) {
      if (&(*it)->next == tail_) {
        tail_ = it;
      }

      ListNode *tmp = *it;
      *it = (*it)->next;

      delete tmp;
    }
  }

private:
  ListNode dummy_;
  ListNode **tail_;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main() {}
