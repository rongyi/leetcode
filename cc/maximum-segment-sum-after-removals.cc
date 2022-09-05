// https://leetcode.com/problems/maximum-segment-sum-after-removals/
#include "xxx.hpp"

class Solution {
public:
  vector<long long> maximumSegmentSum(vector<int> &nums,
                                      vector<int> &removeQueries) {
    int sz = nums.size();
    vector<long long> ret(sz, 0);
    vector<long long> ds(sz, numeric_limits<int>::max());

    for (int i = removeQueries.size() - 1; i > 0; --i) {
      int j = removeQueries[i];

      ds[j] = -nums[j];
      if (j > 0 && ds[j - 1] != numeric_limits<int>::max()) {
        merge(j, j - 1, ds);
      }
      if (j < sz - 1 && ds[j + 1] != numeric_limits<int>::max()) {
        merge(j, j + 1, ds);
      }

      ret[i - 1] = max(ret[i], -ds[find(j, ds)]);
    }

    return ret;
  }

private:
  // https://leetcode.com/problems/maximum-segment-sum-after-removals/discuss/2454208/Reverse-Union-Find
  // root node contain the sum of this group in negative way
  int find(int i, vector<long long> &ds) {
    // if value is negative, it is sum
    if (ds[i] < 0) {
      return i;
    }
    // else it point to parent

    return ds[i] = find(ds[i], ds);
  }

  void merge(int s1, int s2, vector<long long> &ds) {
    int p1 = find(s1, ds);
    int p2 = find(s2, ds);
    ds[p2] += ds[p1];
    // disable p1, now p1's parent point p2;
    ds[p1] = p2;
  }
};
