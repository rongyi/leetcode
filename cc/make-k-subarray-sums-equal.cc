// https://leetcode.com/problems/make-k-subarray-sums-equal/
#include "xxx.hpp"

class Solution {
public:
  long long makeSubKSumEqual(vector<int> &arr, int k) {
    int sz = arr.size();
    long long ret = 0;
    for (int i = 0; i < k; i++) {
      vector<int> group;
      // all the i, i + k, i + 2k, i + 3k... should be same
      for (int j = i; arr[j] != 0; j = (j + k) % sz) {
        group.push_back(arr[j]);
        arr[j] = 0;
      }
      nth_element(group.begin(), group.begin() + group.size() / 2, group.end());
      for (auto &num : group) {
        ret += abs(num - group[group.size() / 2]);
      }
    }

    return ret;
  }
};
