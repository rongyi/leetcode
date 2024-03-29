// http://leetcode.com/problems/data-stream-as-disjoint-intervals/description/
#include "xxx.hpp"

class SummaryRanges {
public:
  /** Initialize your data structure here. */
  SummaryRanges() {}

  void addNum(int val) {
    if (store_.find(val) != store_.end()) {
      return;
    }
    if (store_.empty()) {
      store_[val] = val;
      return;
    }
    store_[val] = val;
    do_merge(val);
  }

  vector<vector<int>> getIntervals() {
    vector<vector<int>> ret;
    for (auto &kv : store_) {
      ret.push_back({kv.first, kv.second});
    }
    return ret;
  }

private:
  void do_merge(int val) {
    auto it = store_.find(val);
    auto cur = prev(it, 1);
    // cur -> (0, 7)
    // it -> (8, 8)
    // left side merge
    if (cur != store_.end() && cur->second - it->first >= -1) {
      cur->second = max(cur->second, it->second);
      store_.erase(it->first);
      // update it for right side merge
      it = cur;
    }
    // now it -> (0, 8)
    // cur -> (9, 9)
    cur = next(it, 1);
    if (cur != store_.end() && it->second - cur->first >= -1) {
      it->second = max(cur->second, it->second);
      store_.erase(cur->first);
    }
  }

private:
  map<int, int> store_;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
