// https://leetcode.com/problems/sum-of-k-mirror-numbers/
#include "xxx.hpp"

// easy to understand
class Solution {
public:
  long long kMirror(int k, int n) {
    long long sum = 0;
    for (long long d = 1; n; d *= 10) {
      for (long long cur = d; n && cur < d * 10; ++cur) {
        auto m = getPlainNum(cur, true);
        if (isMirrorK(m, k)) {
          sum += m;
          --n;
        }
      }

      for (long long cur = d; n && cur < d * 10; ++cur) {
        auto m = getPlainNum(cur, false);
        if (isMirrorK(m, k)) {
          sum += m;
          --n;
        }
      }
    }

    return sum;
  }

private:
  long long getPlainNum(long long num, bool odd) {
    // patch num to make it mirror
    // e.g. 13 ==> 1331
    // or in odd case ==> 131
    long long p = num;

    if (odd) {
      num /= 10;
    }

    while (num) {
      p = p * 10 + num % 10;
      num /= 10;
    }

    return p;
  }
  string toBaseK(long long num, int k) {
    string ret{};
    while (num) {
      ret += (num % k) + '0';
      num /= k;
    }

    return ret;
  }
  bool isMirrorK(long long &num, int k) {
    string s = toBaseK(num, k);
    int l = 0;
    int r = s.size() - 1;
    while (l < r) {
      if (s[l++] != s[r--]) {
        return false;
      }
    }
    return true;
  }
};
