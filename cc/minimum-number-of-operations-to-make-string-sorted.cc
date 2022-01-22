// http://leetcode.com/problems/minimum-number-of-operations-to-make-string-sorted/description/
#include "xxx.hpp"

class Solution {
public:
  // 这题太难了
  // 这里还有费马小定理
  int makeStringSorted(string s) {
    long long ret = 0;
    map<int, long long> freq;
    for (auto &c : s) {
      freq[c - 'a']++;
    }
    vector<long long> fact(s.size() + 1, 1ll);
    for (int i = 1; i <= s.size(); ++i) {
      fact[i] = (fact[i - 1] * i) % mod_;
    }

    int l = s.size();

    for (auto c : s) {
      l--;
      long long t = 0;
      long long rev = 1;
      // 统计小于当前排列的个数
      for (int i = 0; i < 26; i++) {
        // 当前这个位置上比 i 还小的都算，固定这个位置后面的是 位置长度 阶乘
        // 这里用fact[l]来cache
        if (i < c - 'a') {
          t += freq[i];
        }
        // 要除以的个数
        rev = (rev * fact[freq[i]]) % mod_;
      }
      // 这里的除法变成乘法
      ret += (t * fact[l] % mod_) * modpow(rev, mod_ - 2);
      ret %= mod_;

      freq[c - 'a']--;
    }

    return ret;
  }

private:
  long long modpow(long long b, long long p) {
    long long ret = 1;
    for (; p; p >>= 1) {
      if (p & 1) {
        ret = ret * b % mod_;
      }
      b = b * b % mod_;
    }

    return ret;
  }

private:
  const int mod_ = 1e9 + 7;
};
