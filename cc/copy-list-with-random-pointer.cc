// http://leetcode.com/problems/copy-list-with-random-pointer/description/
#include <map>
using namespace std;

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

class Solution2 {
public:
  Node *copyRandomList(Node *head) {
    Node ret(-1);
    Node *p = head;
    Node *prev = nullptr;

    while (p) {
      Node *cp = new Node(p->val);
      prev = p;
      p = p->next;

      prev->next = cp;
      cp->next = p;
    }
    p = head;
    while (p) {
      if (p->random) {
        p->next->random = p->random->next;
      }

      p = p->next->next;
    }
    p = head;
    Node *tail = &ret;
    while (p) {
      tail->next = p->next;
      tail = tail->next;
      p->next = tail->next;
      p = p->next;
    }

    return ret.next;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    Node ret(-1);
    map<Node *, Node *> cache;
    cache[nullptr] = nullptr;

    Node *p = head;
    Node *tail = &ret;
    while (p) {
      tail->next = new Node(p->val);
      tail = tail->next;
      cache[p] = tail;
      p = p->next;
    }
    p = head;
    tail = &ret;
    while (p) {
      tail->next->random = cache[p->random];
      tail = tail->next;
      p = p->next;
    }

    return ret.next;
  }
};
