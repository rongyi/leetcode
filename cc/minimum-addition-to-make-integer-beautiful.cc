// https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful/
#include "xxx.hpp"

class Solution {
public:
  long long makeIntegerBeautiful(long long n, int target) {
    auto digi_sum = [](long long n) {
      int dsum = 0;
      while (n) {
        dsum += (n % 10);
        n /= 10;
      }
      return dsum;
    };
    auto digi_list = [](long long n) {
      vector<int> ret;
      while (n) {
        ret.push_back(n % 10);
        n /= 10;
      }
      reverse(ret.begin(), ret.end());

      return ret;
    };
    long long add = 0;
    long long shift = 1;
    vector<int> lst = digi_list(n);

    while (digi_sum(n + add) > target) {
      // [3, 7, 2]
      // [3, 7, 0]
      int cur = lst.back();
      add += shift * ((10 - cur) % 10);
      shift *= 10;

      lst.pop_back();
      if (cur != 0 && lst.size() > 0) {
        lst.back() += 1;
      }
    }

    return add;
  }
};

