// http://leetcode.com/problems/count-nice-pairs-in-an-array/description/
#include "xxx.h"

class Solution {
public:
  int countNicePairs(vector<int> &nums) {
    unordered_map<int, long> diff_count;
    for (auto &n : nums) {
      diff_count[n - revNum(n)]++;
    }
    long long ret = 0;
    const int mod = 1e9 + 7;
    for (auto &kv : diff_count) {
      ret = (ret + (kv.second * (kv.second - 1)) / 2) % mod;
    }

    return ret;
  }

private:
  int revNum(int n) {
    int sum = 0;
    while (n) {
      sum = sum * 10 + (n % 10);
      n /= 10;
    }

    return sum;
  }
};
