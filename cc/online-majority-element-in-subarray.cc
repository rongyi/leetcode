// http://leetcode.com/problems/online-majority-element-in-subarray/description/
#include "xxx.hpp"

class MajorityChecker {
public:
  MajorityChecker(vector<int> &arr) {
    for (int i = 0; i < arr.size(); ++i) {
      index_[arr[i]].push_back(i);
    }
  }

  int query(int left, int right, int threshold) {
    // NOTE!! without reference iteration will get
    // MLE
    for (auto &kv : index_) {
      if (kv.second.size() < threshold) {
        continue;
      }
      auto it1 = lower_bound(begin(kv.second), end(kv.second), left);
      auto it2 = upper_bound(begin(kv.second), end(kv.second), right);
      if (it2 - it1 >= threshold) {
        return kv.first;
      }
    }
    return -1;
  }

public:
  unordered_map<int, vector<int>> index_;
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
