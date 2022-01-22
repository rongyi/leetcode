// http://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/
#include "xxx.hpp"

// Definition for a Node.
class Node {
public:
  int val;
  Node *prev;
  Node *next;
  Node *child;

  Node() {}

  Node(int _val, Node *_prev, Node *_next, Node *_child) {
    val = _val;
    prev = _prev;
    next = _next;
    child = _child;
  }
};

class Solution {
public:
  // 把这个题目竖起来看就是个二叉树的前序遍历。
  // 先遍历一遍把顺序排好，然后再串起来。
  Node *flatten(Node *head) {
    vector<Node *> ret;
    inorder(head, ret);
    const int n = ret.size();
    if (n == 0) {
      return nullptr;
    }
    for (int i = 0; i < n; i++) {
      // clear all child field
      ret[i]->child = nullptr;
      // chain prev
      if (i != 0) {
        ret[i]->prev = ret[i - 1];
      }
      // chain next
      if (i != n - 1) {
        ret[i]->next = ret[i + 1];
      }
    }

    // clear the first prev and last next
    ret[0]->prev = nullptr;
    ret[n - 1]->next = nullptr;

    return ret[0];
  }

private:
  void inorder(Node *head, vector<Node *> &ret) {
    if (!head) {
      return;
    }
    ret.push_back(head);
    inorder(head->child, ret);
    inorder(head->next, ret);
  }
};
