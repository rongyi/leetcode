// http://leetcode.com/problems/permutation-sequence/description/
#include "xxx.hpp"

class Solution {
public:
  string getPermutation(int n, int k) {
    // make it start from 0
    k--;

    vector<int> facts(n + 1, 1);
    for (int i = 2; i <= n; i++) {
      facts[i] = facts[i - 1] * i;
    }
    vector<int> nums(n, 0);
    iota(nums.begin(), nums.end(), 1);

    ostringstream oss;
    collect(n, k, facts, nums, oss);

    return oss.str();
  }

private:
  void collect(int n, int k, std::vector<int> &facts, std::vector<int> nums,
               ostringstream &oss) {
    if (n == 1) {
      oss << nums.back();
      return;
    }
    int idx = k / facts[n - 1];
    oss << nums[idx];

    nums.erase(nums.begin() + idx);
    k %= facts[n - 1];

    // digit decrese
    collect(n - 1, k, facts, nums, oss);
  }
};
