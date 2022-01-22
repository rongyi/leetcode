// https://leetcode.com/problems/longest-common-subpath/
#include "xxx.hpp"

// So, the key point here is to check whether there is some common substrings
// with length middle. A usual way is to adopt Hash. For my preference, I would
// like to use Rabin-Karp hash, which is treat a string like a MAGIC based
// number. That is,

// Hash(S[0..n-1]) = (S[n-1] * MAGIC^0 + S[n-2] * MAGIC^1 + .. + S[n-1-i] *
// MAGIC^i + ... ) % MOD
// The most convenient point here, is that we can use
// Hash(S[0…i]) to calculate the Hash(S[l…r]) in O(1) time, with O(N)
// preparation. That is,

// Hash(S[l..r]) = (Hash(S[0..r]) - Hash(S[0..l-1]) * MAGIC^(r-l+1)) % MOD

using ll = long long;
class Solution {
public:
  int longestCommonSubpath(int n, vector<vector<int>> &paths) {
    n_ = n;
    m_ = paths.size();
    int min_len = numeric_limits<int>::max();
    for (int i = 0; i < m_; ++i) {
      min_len = min(min_len, (int)paths[i].size());
    }
    int start = 0;
    int end = min_len;
    while (start <= end) {
      auto mid = (start + end) / 2;
      if (check(paths, mid)) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    return end;
  }

private:
  bool check(vector<vector<int>> &paths, int len) {
    if (len == 0) {
      return true;
    }
    map<ll, int> freq;
    for (int i = 0; i < m_; ++i) {
      ll cur_hash = 0;
      ll pow = 1;
      set<ll> found_hashes;
      for (int j = 0; j < len; ++j) {
        cur_hash = (cur_hash * p_) % mod_;
        cur_hash += paths[i][j];
        // you get that?
        // pow = magic ^ len
        // if we still calculate the at len - 1
        // pow will be magic ^ (len + 1)
        if (j != len - 1) {
          pow = (pow * p_) % mod_;
        }
      }
      found_hashes.insert(cur_hash);
      // rolling at window size: len
      for (int j = len; j < paths[i].size(); ++j) {
        // incase negative
        cur_hash += mod_;
        cur_hash -= (paths[i][j - len] * pow) % mod_;
        cur_hash %= mod_;
        cur_hash = cur_hash * p_;
        cur_hash %= mod_;

        cur_hash += paths[i][j];
        cur_hash %= mod_;
        found_hashes.insert(cur_hash);
      }
      while (found_hashes.size()) {
        auto it = found_hashes.begin();
        auto h = *it;
        found_hashes.erase(it);
        freq[h]++;
        if (freq[h] == m_) {
          return true;
        }
      }
    }
    return false;
  }

private:
  // magic base
  const ll p_ = 1299827;
  const ll mod_ = 1e11 + 7;
  ll m_;
  ll n_;
};
