// http://leetcode.com/problems/lru-cache/description/
#include "xxx.hpp"
class LRUCache {
public:
  LRUCache(int capacity) : cap_(capacity) {}

  int get(int key) {
    if (!pos_.count(key)) {
      return -1;
    }
    auto it = pos_[key];
    int val = it->second;

    vals_.erase(it);
    vals_.push_front({key, val});
    pos_[key] = vals_.begin();

    return val;
  }

  void put(int key, int value) {
    if (pos_.count(key)) {
      vals_.erase(pos_[key]);
    }
    vals_.push_front({key, value});
    pos_[key] = vals_.begin();

    // shrink
    if (vals_.size() > cap_) {
      pos_.erase(vals_.back().first);
      vals_.pop_back();
    }
  }

private:
  int cap_;
  map<int, list<pair<int, int>>::iterator> pos_;
  list<pair<int, int>> vals_;
};

