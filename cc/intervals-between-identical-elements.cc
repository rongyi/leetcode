// https://leetcode.com/problems/intervals-between-identical-elements/
#include "xxx.hpp"

class Solution {
public:
  vector<long long> getDistances(vector<int> &arr) {
    using ll = long long;
    int sz = arr.size();
    map<int, vector<int>> group;
    for (int i = 0; i < sz; ++i) {
      group[arr[i]].push_back(i);
    }
    vector<ll> ret(sz, 0);
    for (auto &kv : group) {
      auto &vec = kv.second;
      int cursz = vec.size();
      // i j k l m
      //     ^
      // (k - i) + (k - j) ==> 2k - (i + j) which (i + j) is prefixsum
      // (l - k) + (m - k) ==> (l + m) - 2k which(l + m) is suffixsum
      // 1..cursz realvalue
      vector<ll> prefix(cursz + 1, 0);
      // 0..cursz - 1 realvalue
      vector<ll> suffix(cursz + 1, 0);
      for (int i = 0; i < cursz; ++i) {
        prefix[i + 1] = prefix[i] + vec[i];
      }
      for (int i = cursz - 1; i >= 0; --i) {
        suffix[i] = suffix[i + 1] + vec[i];
      }
      for (long long i = 0; i < cursz; ++i) {
        ret[vec[i]] += i * vec[i] - prefix[i /* - 1 + 1*/];
        ret[vec[i]] += suffix[i + 1] - vec[i] * (cursz - (i + 1));
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{2, 1, 3, 1, 2, 3, 3};
  so.getDistances(input);
}
