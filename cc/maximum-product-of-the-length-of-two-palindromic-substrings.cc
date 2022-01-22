// https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-substrings/
#include "xxx.hpp"

using ll = long long;
class Solution {

public:
  ll maxProduct(string s) {
    int n = s.size();
    lh_.resize(n + 1);
    // value put in index 1..n
    rh_.resize(n + 1);
    // value put in index 0..n-1
    pow_.resize(n + 1);
    pow_[0] = 1;
    int p = 1;
    for (int i = 0; i < n; ++i) {
      pow_[i + 1] = (base_ * pow_[i]) % mod_;
      // from left -> right, i value put in i + 1
      lh_[i + 1] = (base_ * lh_[i] + s[i] - 'a') % mod_;
      // from right -> left, i value put in i
      rh_[n - i - 1] = (base_ * rh_[n - i] + s[n - i - 1] - 'a') % mod_;
    }
    vector<ll> left(n);
    vector<ll> right(n);
    for (int i = 0, maxlen = 1; i < n; ++i) {
      // i + 1 means length till i
      // i - (i - maxlen - 1) + 1 ==  maxlen + 2
      if (i + 1 >= maxlen + 2 && isPalindrome(i - maxlen - 1, i)) {
        maxlen += 2;
      }
      left[i] = maxlen;
    }
    for (int i = n - 1, maxlen = 1; i >= 0; i--) {
      // from i to end, i + maxlen + 2 should n
      // i + maxlen + 1 - i + 1 == maxlen + 1
      if (i + maxlen + 2 <= n && isPalindrome(i, i + maxlen + 1)) {
        maxlen += 2;
      }
      right[i] = maxlen;
    }
    ll ret = 0;
    for (int i = 0; i + 1 < n; ++i) {
      ret = max(ret, left[i] * right[i + 1]);
    }
    return ret;
  }

private:
  bool isPalindrome(int l, int r) { return fromleft(l, r) == fromright(l, r); }
  ll fromleft(int l, int r) {
    return (lh_[r + 1] - (lh_[l] * pow_[r - l + 1]) % mod_ + mod_) % mod_;
  }
  ll fromright(int l, int r) {
    return (rh_[l] - (rh_[r + 1] * pow_[r - l + 1] % mod_) + mod_) % mod_;
  }

private:
  static constexpr ll base_ = 29;
  static constexpr ll mod_ = 1e9 + 7;
  vector<ll> lh_;
  vector<ll> rh_;
  vector<ll> pow_;
};
