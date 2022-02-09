// https://leetcode.com/problems/range-frequency-queries/
#include "xxx.hpp"

class RangeFreqQuery {
public:
  RangeFreqQuery(vector<int> &arr) {
    for (int i = 0; i < arr.size(); ++i) {
      idxs_[arr[i]].push_back(i);
    }
  }

  int query(int left, int right, int value) {
    auto &cur_idxs = idxs_[value];
    int ret = 0;
    // use O(n) search still get TLE
    auto l = lower_bound(cur_idxs.begin(), cur_idxs.end(), left);
    auto r = lower_bound(cur_idxs.begin(), cur_idxs.end(), right + 1);

    return r - l;
  }

private:
  map<int, vector<int>> idxs_;
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */

class RangeFreqQueryTLE {
public:
  RangeFreqQueryTLE(vector<int> &arr) {
    int sz = arr.size();
    prefix_ = vector<map<int, int>>(sz + 1);
    map<int, int> cur;
    for (int i = 0; i < sz; ++i) {
      cur[arr[i]]++;
      prefix_[i + 1] = cur;
    }
  }

  // inclusive range [left, right]
  int query(int left, int right, int value) {
    auto l = prefix_[left][value];
    auto r = prefix_[right + 1][value];

    return r - l;
  }

private:
  vector<map<int, int>> prefix_;
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
