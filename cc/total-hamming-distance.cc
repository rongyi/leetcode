// http://leetcode.com/problems/total-hamming-distance/description/
#include "xxx.hpp"

class Solution {
public:
  // 全局的看每一位，如果该位上0的个数有n个，1的个数有q个，那么对结果的贡献就是 p * q
  // 为什么？因为通过TLE的版本可以看到碰撞的方式就是每个0会和每个1碰撞一次并且产生结果
  int totalHammingDistance(vector<int> &nums) {
    int ret = 0;
    const int n = nums.size();
    for (int i = 0; i < 32; i++) {
      int bit_count = 0;
      for (auto num : nums) {
        bit_count += (num >> i) & 1;
      }
      ret += bit_count * (n - bit_count);
    }
    return ret;
  }
  int totalHammingDistanceTLEVersion(vector<int> &nums) {
    int ret = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        ret += hammingDistance(nums[i], nums[j]);
      }
    }

    return ret;
  }
  int hammingDistance(int x, int y) {
    int ret = 0;
    auto val = x ^ y;

    while (val != 0) {
      ret++;
      val &= val - 1;
    }

    return ret;
  }
};
