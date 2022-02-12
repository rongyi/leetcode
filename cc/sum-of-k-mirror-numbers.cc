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


class Solution1 {
public:
  // n smallest mirror number in base 10 and base k
  long long kMirror(int k, int n) {
    long long ret = 0;
    for (int i = 1; n > 0 && i < 10; ++i) {
      mirror2_.push_back(i);
      if (isMirror(i, k)) {
        ret += i;
        --n;
      }
    }
    return ret + generate(2, n, k, 10);
  }

private:
  long long isMirror(long long num, int base) {
    long long mul = 1;
    // count how many digits of num in base *base*
    while (mul * base <= num) {
      mul *= base;
    }
    while (num) {
      // highest digit and lowest digit cmp
      if (num / mul != num % base) {
        return false;
      }
      //        delete higest digit    lowest digit
      //                 |                   |
      //            ________________   __________
      // 1234 -> 230 -> 23 (the divide operation)
      num = (num - (num / mul) * mul - num % base) / base;

      mul /= base * base;
    }

    return true;
  }

  long long generate(int dig, int n, int k, long long first_mul) {
    vector<long long> mirror;
    long long ret = 0;
    for (int i = 0; n > 0 && i < 10; ++i) {
      for (int j = 0; n > 0 && j < mirror1_.size(); ++j) {
        mirror.push_back(first_mul * i + mirror1_[j] * 10 + i);
        if (i != 0 && isMirror(mirror.back(), k)) {
          ret += mirror.back();
          --n;
        }
      }
    }
    swap(mirror1_, mirror2_);
    swap(mirror2_, mirror);

    return ret + (n == 0 ? 0 : generate(dig + 1, n, k, first_mul * 10));
  }

private:
  vector<long long> mirror1_{0};
  vector<long long> mirror2_{0};
};

int main() {
  Solution1 so;
  auto ret = so.kMirror(2, 20);
  cout << ret << endl;
}
