// https://leetcode.com/problems/minimum-time-to-repair-cars/
#include "xxx.hpp"

class Solution {
public:
  long long repairCars(vector<int> &ranks, int cars) {
    long long l = 0;
    long long r = (long long)cars * (long long)cars * 100;
    long long ret = r;
    while (l <= r) {
      long long mid = l + (r - l) / 2;
      if (check(mid, ranks, cars)) {
        ret = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return ret;
  }

private:
  bool check(long long t, vector<int> &ranks, int cars) {
    for (int i = 0; i < ranks.size() && cars > 0; i++) {
      // with rank[i] can repaire n cars in t = rank[i] * n * n
      // so n = sqrt(t / rank[i])
      int repair = sqrt(t / ranks[i]);
      cars -= repair;
    }
    if (cars > 0) {
      return false;
    }

    return true;
  }
};
