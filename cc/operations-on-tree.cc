// https://leetcode.com/problems/operations-on-tree/
#include "xxx.hpp"

class LockingTree {
public:
  LockingTree(vector<int> &parent) {
    parent_ = parent;
    for (int i = 1; i < parent.size(); ++i) {
      child_[parent[i]].push_back(i);
    }
  }

  bool lock(int num, int user) {
    if (lock_user_.find(num) == lock_user_.end()) {
      lock_user_[num] = user;
      return true;
    }
    // already locked by others
    return false;
  }

  bool unlock(int num, int user) {
    // locked and locked by this user
    if (lock_user_.find(num) != lock_user_.end() && lock_user_[num] == user) {
      lock_user_.erase(num);
      return true;
    }

    // otherwise
    return false;
  }

  bool upgrade(int num, int user) {
    // 1. current node must be unlocked, else we just return false;
    if (lock_user_.find(num) != lock_user_.end()) {
      return false;
    }
    // 2. at lease one desendant locked by *any* user
    // 3. It does not have any locked ancestors.
    // ancestorAllFree first make code a bit faster
    if (ancestorAllFree(parent_[num]) && childHasOneLocked(num)) {
      lock_user_[num] = user;
      unlockChildOf(num);

      return true;
    }

    return false;
  }

private:
  bool ancestorAllFree(int num) {
    // we find to the root, so no one is locked
    // yes, all node is free
    if (num == -1) {
      return true;
    }
    // this one has locked!
    if (lock_user_.find(num) != lock_user_.end()) {
      return false;
    }

    // check node's parent
    return ancestorAllFree(parent_[num]);
  }

  bool childHasOneLocked(int num) {
    for (auto c : child_[num]) {
      if (lock_user_.find(c) != lock_user_.end()) {
        return true;
      }
      // else we iter their child
      if (childHasOneLocked(c)) {
        return true;
      }
    }

    return false;
  }

  void unlockChildOf(int num) {
    for (auto c : child_[num]) {
      // erase the child, not current num!
      lock_user_.erase(c); // writing c -> num cost me half hour to debug, shit!
      // and its child
      unlockChildOf(c);
    }
  }

private:
  vector<int> parent_;
  map<int, int> lock_user_;
  map<int, vector<int>> child_;
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */

int main() {
  vector<int> input{-1, 0, 0, 1, 1, 2, 2};
  LockingTree lt(input);
  bool b = lt.lock(2, 2);
  b = lt.unlock(2, 3);
  b = lt.unlock(2, 2);
  b = lt.lock(4, 5);
  b = lt.upgrade(0, 1);
  b = lt.lock(0, 1);
}

