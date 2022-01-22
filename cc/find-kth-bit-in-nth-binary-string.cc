// http://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/
#include "xxx.hpp"

class Solution {
public:
  char findKthBit(int n, int k) {
    if (cache_.size() < n + 1) {
      cache_.resize(n + 1);
    }
    string whole = kth(n);

    return whole[k - 1];
  }

private:
  string kth(int n) {
    if (n == 1) {
      cache_[n] = "0";
      return cache_[n];
    }
    if (cache_[n] != "") {
      return cache_[n];
    }

    string prev = kth(n - 1);
    string suffix = invert(prev);
    reverse(suffix.begin(), suffix.end());

    cache_[n] = prev + "1" + suffix;

    return cache_[n];
  }
  string invert(string s) {
    string ret{};
    for (auto c : s) {
      ret.push_back(c - '0' == 0 ? '1' : '0');
    }
    return ret;
  }

private:
  vector<string> cache_;
};
