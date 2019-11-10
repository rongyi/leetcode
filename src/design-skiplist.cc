// http://leetcode.com/problems/design-skiplist/description/
#include "xxx.h"

// https://leetcode.com/problems/design-skiplist/discuss/400028/C%2B%2B-SkipList.-2-pointer-for-each-node.-64ms.
class Skiplist {
public:
  struct Node {
    Node *right_;
    Node *down_;
    int val_;
    Node(Node *right, Node *down, int val)
        : right_(right), down_(down), val_(val) {}
  };
  Skiplist() { head_ = new Node(nullptr, nullptr, 0); }

  bool search(int target) {
    Node *p = head_;
    while (p) {
      while (p->right_ && p->right_->val_ < target) {
        p = p->right_;
      }
      if (p->right_ && p->right_->val_ == target) {
        return true;
      }
      p = p->down_;
    }
    return false;
  }

  void add(int num) {
    insert_points_.clear();
    Node *p = head_;
    while (p) {
      while (p->right_ && p->right_->val_ < num) {
        p = p->right_;
      }
      insert_points_.push_back(p);
      p = p->down_;
    }
    Node *down_node = nullptr;
    bool insert_up = true;
    while (insert_up && insert_points_.size()) {
      Node *ins = insert_points_.back();
      insert_points_.pop_back();

      //   ins --> new node --> ins->right(old next of ins)
      //             |
      //             v
      //          down_node
      ins->right_ = new Node(ins->right_, down_node, num);
      // the new nodea become down_node for next insertion
      down_node = ins->right_;
      insert_up = (rand() & 1) == 0;
    }

    // head_ ---> newnode(num)
    //   |           |
    //   v           v
    //  old_head    down_node
    if (insert_up) {
      head_ = new Node(new Node(nullptr, down_node, num), head_, 0);
    }
  }

  bool erase(int num) {
    Node *p = head_;
    bool seen = false;
    while (p) {
      while (p->right_ && p->right_->val_ < num) {
        p = p->right_;
      }
      if (p->right_ && p->right_->val_ == num) {
        seen = true;
        // delete this node
        p->right_ = p->right_->right_;
      }
      p = p->down_;
    }

    return seen;
  }

private:
  Node *head_;
  vector<Node *> insert_points_;
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
