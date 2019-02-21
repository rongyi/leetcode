// http://leetcode.com/problems/lfu-cache/description/
#include "xxx.h"

class LFUCache {
public:
  LFUCache(int capacity) : capacity_(capacity), size_(0) {
    // capacity_ = capacity;
    // size_ = 0;
  }

  int get(int key) {
    if (values_.find(key) == values_.end()) {
      return -1;
    }
    update(key);
    return values_[key].first;
  }

  void put(int key, int value) {
    if (!capacity_) {
      return;
    }
    if (values_.find(key) != values_.end()) {
      values_[key].first = value;
      update(key);
    } else {
      if (size_ == capacity_) {
        int evict = keys_[lfu_].front();
        keys_[lfu_].pop_front();
        values_.erase(evict);
        iters_.erase(evict);
      } else {
        size_++;
      }
      values_[key] = {value, 1};
      keys_[1].push_back(key);
      iters_[key] = --keys_[1].end();
      lfu_ = 1;
    }
  }

private:
  void update(int key) {
    int old_freq = values_[key].second;
    auto iter = iters_[key];

    // delete old
    values_[key].second++;
    keys_[old_freq].erase(iter);

    // update new
    keys_[old_freq + 1].push_back(key);
    iters_[key] = --keys_[old_freq + 1].end();

    if (keys_[lfu_].empty()) {
      lfu_++;
    }
  }

private:
  int capacity_;
  int size_; // 当前元素多少个？
  int lfu_;  // 标记最小频率是多少
  // key -> {value, freq}
  unordered_map<int, pair<int, int>> values_;
  // freq -> key list
  unordered_map<int, list<int>> keys_;
  // 标记 key 在 list<int>中的位置，为的是删除O(1)
  unordered_map<int, list<int>::iterator> iters_;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
