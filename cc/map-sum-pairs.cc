// http://leetcode.com/problems/map-sum-pairs/description/
#include "xxx.h"

class MapSum {
public:
  /** Initialize your data structure here. */
  MapSum() {}

  void insert(string key, int val) { count_[key] = val; }

  int sum(string prefix) {
    int ret = 0;
    for (auto kv : count_) {
      if (kv.first.size() < prefix.size()) {
        continue;
      }
      if (prefix == kv.first.substr(0, prefix.size())) {
        ret += kv.second;
      }
    }

    return ret;
  }

private:
  unordered_map<string, int> count_;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
