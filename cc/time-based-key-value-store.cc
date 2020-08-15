// http://leetcode.com/problems/time-based-key-value-store/description/
#include "xxx.h"

class TimeMap {
public:
  /** Initialize your data structure here. */
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    cache_[key].insert({timestamp, value});
  }

  string get(string key, int timestamp) {
    auto it = cache_[key].upper_bound(timestamp);
    if (it == cache_[key].begin()) {
      return "";
    }
    return prev(it)->second;
  }
private:
  unordered_map<string, map<int, string>> cache_;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
