// https://leetcode.com/problems/operations-on-tree/
#include "xxx.h"

class LockingTree {
public:
  LockingTree(vector<int> &parent) {
    parent_ = parent;
    node_nums_ = parent.size();
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
    // 3. ancestor have not locked(all)
    if (!ancestorHasNoLocked(parent_[num])) {
      return false;
    }
  }

private:
  bool ancestorHasNoLocked(int num) {
    if (num == -1) {
      return true;
    }
    // this one has locked!
    if (lock_user_.find(num) != lock_user_.end()) {
      return false;
    }
    return ancestorHasNoLocked(parent_[num]);
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

private:
  vector<int> parent_;
  int node_nums_;
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
