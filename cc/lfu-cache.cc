// http://leetcode.com/problems/lfu-cache/description/
#include "xxx.h"

class LFUCache {
public:
  LFUCache(int capacity) : capacity_(capacity), size_(0) {}

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
      // update value
      values_[key].first = value;
      update(key);
    } else {
      // need evict the smallest freq?
      if (size_ == capacity_) {
        int delkey = freqs_[min_lfu_].front();
        values_.erase(delkey);
        freqs_[min_lfu_].pop_front();
        key_in_freqs_.erase(delkey);
      } else {
        size_++;
      }
      values_[key] = {value, 1};
      freqs_[1].push_back(key);
      key_in_freqs_[key] = prev(freqs_[1].end());
      min_lfu_ = 1;
    }
  }

private:
  void update(int key) {
    int old_freq = values_[key].second;
    // delete old freq
    freqs_[old_freq].erase(key_in_freqs_[key]);
    key_in_freqs_.erase(key);

    // update
    values_[key].second++;
    freqs_[old_freq + 1].push_back(key);
    key_in_freqs_[key] = prev(freqs_[old_freq + 1].end());

    // low freq is deleted
    if (freqs_[min_lfu_].empty()) {
      min_lfu_++;
    }
  }

private:
  int capacity_;
  int size_;
  int min_lfu_;
  // key -> {value, freq}
  unordered_map<int, pair<int, int>> values_;
  // freq -> {key...}
  unordered_map<int, list<int>> freqs_;
  // key -> { ... pos ...}
  unordered_map<int, list<int>::iterator> key_in_freqs_;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
