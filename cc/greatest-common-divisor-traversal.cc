// https://leetcode.com/problems/greatest-common-divisor-traversal/
#include "xxx.hpp"

class Solution {
public:
  bool canTraverseAllPairs(vector<int> &nums) {
    int sz = nums.size();
    if (sz == 1) {
      return true;
    }
    parent_.resize(sz);
    group_sz_.resize(sz, 1);
    // initial group with one of itself
    iota(parent_.begin(), parent_.end(), 0);

    // last index for prime we see till now
    map<int, int> primes;
    for (int i = 0; i < sz; i++) {
      if (nums[i] == 1) {
        return false;
      }
      auto curps = primeFactors(nums[i]);
      for (auto p : curps) {
        if (primes.count(p)) {
          connect(primes[p], i);
        } else {
          primes[p] = i;
        }
      }
    }

    return group_sz_[getParent(0)] == sz;
  }

private:
  vector<int> primeFactors(int num) {
    vector<int> ps;
    for (int i = 2; i * i <= num; i++) {
      if (num % i == 0) {
        ps.push_back(i);
        while (num % i == 0) {
          num /= i;
        }
      }
    }
    if (num != 1) {
      ps.push_back(num);
    }

    return ps;
  }
  int getParent(int x) {
    if (parent_[x] == x) {
      return x;
    }
    return parent_[x] = getParent(parent_[x]);
  }
  void connect(int x, int y) {
    auto px = getParent(x);
    auto py = getParent(y);
    if (px != py) {
      if (group_sz_[px] < group_sz_[py]) {
        swap(px, py);
      }
      parent_[py] = px;
      group_sz_[px] += group_sz_[py];
    }
  }

private:
  vector<int> parent_;
  vector<int> group_sz_;
};
