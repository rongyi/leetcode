// https://leetcode.com/problems/split-the-array-to-make-coprime-products/
#include "xxx.hpp"

class Solution {
public:
  int findValidSplit(vector<int> &nums) {
    initSpf();
    int sz = nums.size();
    // If element i shares the same prime as element j, we cannot split the
    // array in [i, j) interval.
    int line[10001] = {};
    map<int, int> fidx;
    for (int i = 0; i < sz; i++) {
      for (auto p : getFactors(nums[i])) {
        // line sweep,
        if (fidx.count(p) == 0) {
          fidx[p] = i;
        }
        ++line[fidx[p]];
        --line[i];
      }
    }
    partial_sum(begin(line), end(line), begin(line));
    int ret = find(begin(line), end(line), 0) - begin(line);
    if (ret < sz - 1) {
      return ret;
    }

    return -1;
  }

private:
  void initSpf() {
    int n = 1e6;
    spf_.resize(n + 1);
    iota(spf_.begin(), spf_.end(), 0);

    for (int i = 2; i * i <= n; i++) {
      // already edited
      if (spf_[i] != i) {
        continue;
      }
      for (int j = i * i; j <= n; j += i) {
        if (spf_[j] == j) {
          spf_[j] = i;
        }
      }
    }
  }
  vector<int> getFactors(int num) {
    vector<int> ret;
    while (num > 1) {
      ret.push_back(spf_[num]);
      num /= spf_[num];
    }

    return ret;
  }

private:
  // prime factors from 1 .. maxvalue
  vector<int> spf_;
};
