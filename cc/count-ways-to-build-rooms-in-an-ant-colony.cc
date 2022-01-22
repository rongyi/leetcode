// https://leetcode.com/problems/count-ways-to-build-rooms-in-an-ant-colony/
#include "xxx.hpp"
using ll = long long;
class Solution {
public:
  // combination problems
  int waysToBuildRooms(vector<int> &prevRoom) {
    int n = prevRoom.size();
    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
      // parent has those child
      g[prevRoom[i]].push_back(i);
    }
    vector<ll> fac(n + 1, 1);
    vector<ll> inverse(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
      fac[i] = fac[i - 1] * i % mod_;
      // modular inverse
      // a ^ (p - 1) == 1 (mod p)
      inverse[i] = modpow(fac[i], mod_ - 2);
    }

    return dfs(g, fac, inverse, 0).first;
  }

private:
  ll modpow(ll x, unsigned n) {
    ll ret = 1;
    for (auto i = n; i; i /= 2) {
      if (i & 1) {
        ret = ret * x % mod_;
      }
      x = x * x % mod_;
    }

    return ret;
  }
  //   l, r
  pair<ll, ll> dfs(vector<vector<int>> &g, vector<ll> &fac, vector<ll> &inverse,
                   int cur) {
    if (g[cur].size() == 0) {
      return {1, 1};
    }
    ll ret = 1;
    ll l = 0;
    for (int nxt : g[cur]) {
      auto [tmp, r] = dfs(g, fac, inverse, nxt);
      ll comb = (((fac[l + r] * inverse[l]) % mod_) * inverse[r]) % mod_;
      ret = (ret * tmp % mod_) * comb % mod_;
      // merge r to l, and l will be the r for next round
      l += r;
    }
    // including cur itself, so l plus 1
    return {ret, l + 1};
  }

private:
  static constexpr int mod_ = 1e9 + 7;
};
