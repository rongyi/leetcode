// http://leetcode.com/problems/lru-cache/description/
#include "one.h"
using itor = list<pair<int, int>>::iterator;

class LRUCache {
public:
  LRUCache(int capacity) : capacity_(capacity) {}

  int get(int key) {
    if (index_.find(key) == index_.end()) {
      return -1;
    }
    // else we put this value to beginning before return
    auto cur = index_[key];
    vec_.splice(vec_.begin(), vec_, cur);
    index_[key] = vec_.begin();

    return vec_.begin()->second;
  }

  void put(int key, int value) {
    // fresh new element
    if (index_.find(key) == index_.end()) {
      // before insert we should check capacity
      if (vec_.size() == capacity_) {
        // 需要删除的key是最后一个
        index_.erase(vec_.back().first);
        vec_.pop_back();
      }
      vec_.push_front(make_pair(key, value));
      index_[key] = vec_.begin();
    } else {
      // move this item to begin
      // update first
      *index_[key] = make_pair(key, value);
      vec_.splice(vec_.begin(), vec_, index_[key]);
      index_[key] = vec_.begin();
    }
  }

private:
  int capacity_;
  list<pair<int, int>> vec_;
  // map is faster than unordered_map?
  map<int, itor> index_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
