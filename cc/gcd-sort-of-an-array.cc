// https://leetcode.com/problems/gcd-sort-of-an-array/
#include "xxx.h"

class Solution {
public:
  bool gcdSort(vector<int> &nums) {
    int max_num = *max_element(nums.begin(), nums.end());
    sieve(max_num + 1);

    UnionFind uf(max_num + 1);
    for (auto x : nums) {
      // for gdb
      auto cur = getPrimeFactors(x);
      for (auto f : cur) {
        uf.group(x, f);
      }
    }
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < nums.size(); ++i) {
      //if (uf.find(nums[i]) != uf.find(sorted[i])) {
        //return false;
      //}
      auto l = uf.find(nums[i]);
      auto r = uf.find(sorted[i]);
      if (l != r) {
        return false;
      }
    }
    return true;
  }

  void sieve(int n) {
    spf_.resize(n);
    for (int i = 2; i < n; ++i) {
      spf_[i] = i;
    }
    for (int i = 2; i * i < n; ++i) {
      if (spf_[i] != i) {
        continue;
      }
      // this part is so elegant,
      // 1 2 3 4 ==> will change to
      // 1 2 3 2
      for (int j = i * i; j < n; j += i) {
        if (spf_[j] > i) {
          spf_[j] = i;
        }
      }
    }
  }

  vector<int> getPrimeFactors(int n) {
    vector<int> factors;

    while (n > 1) {
      factors.push_back(spf_[n]);
      n /= spf_[n];
    }

    return factors;
  }

private:
  struct UnionFind {
    vector<int> parent_;
    UnionFind(int n) {
      parent_.resize(n);
      for (int i = 0; i < n; ++i) {
        parent_[i] = i;
      }
    }
    // x is the group num
    int find(int x) {
      if (x == parent_[x]) {
        return x;
      }
      // search all the way down, and cache it
      return parent_[x] = find(parent_[x]);
    }
    void group(int u, int v) {
      int pu = find(u);
      int pv = find(v);
      if (pu != pv) {
        parent_[pu] = pv;
      }
    }
  };

private:
  // smallest prime factor
  vector<int> spf_;
};

int main() {
  Solution so;
  vector<int> input{7, 21, 3};
  so.gcdSort(input);
}
