// https://leetcode.com/problems/count-the-number-of-square-free-subsets/
#include "xxx.hpp"

class Solution {
public:
  int squareFreeSubsets(vector<int> &nums) {
    // prim below 30
    primes_ = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int sz = nums.size();
    // total 10 prime and we don't use the lowest value
    dp_ = vector<vector<int>>(sz, vector<int>(1 << 11, -1));
    mod_ = 1e9 + 7;

    return (dfs(nums, 0, 1) - 1 + mod_) % mod_;
  }

private:
  int dfs(vector<int> &nums, int idx, long long curmask) {
    // find one
    if (idx >= nums.size()) {
      return 1;
    }
    if (dp_[idx][curmask] != -1) {
      return dp_[idx][curmask];
    }

    long long mask = getMask(nums[idx]);

    // don't take current
    long long ret = dfs(nums, idx + 1, curmask);
    // take current but with condition satisfied
    if ((curmask & mask) == 0) {
      ret = (ret + dfs(nums, idx + 1, curmask | mask)) % mod_;
    }

    return dp_[idx][curmask] = ret;
  }

  int getMask(int num) {
    int mask = 0;
    for (int i = 0; i < primes_.size(); i++) {
      int p = primes_[i];
      int rep = 0;
      while (num % p == 0) {
        rep++;
        num /= p;
      }
      if (rep > 1) {
        return -1;
      }
      if (rep == 1) {
        // why +1?, because mask initial value
        // is 0, so we need to diff that case
        mask |= (1 << (i + 1));
      }
    }
    return mask;
  }

private:
  vector<int> primes_;
  vector<vector<int>> dp_;
  int mod_;
};

int main() { cout << (3 & -1) << endl; }
