// http://leetcode.com/problems/permutation-sequence/description/
#include "xxx.hpp"

class Solution {
public:
  string getPermutation(int n, int k) {
    // make k start from 0
    k--;
    vector<int> nums(n, 0);
    iota(nums.begin(), nums.end(), 1);

    vector<int> facts(n + 1, 1);
    for (int i = 2; i <= n; i++) {
      facts[i] = facts[i - 1] * i;
    }
    ostringstream oss;

    collect(n, k, nums, facts, oss);

    return oss.str();
  }

private:
  void collect(int n, int k, vector<int> &nums, vector<int> &facts,
               ostringstream &oss) {
    if (n == 1) {
      oss << nums.back();
      return;
    }
    int idx = k / facts[n - 1];
    oss << nums[idx];
    nums.erase(nums.begin() + idx);
    k %= facts[n - 1];

    collect(n - 1, k, nums, facts, oss);
  }
};
