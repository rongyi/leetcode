// http://leetcode.com/problems/maximum-xor-for-each-query/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> getMaximumXor(vector<int> &nums, int maximumBit) {
    // make num maximum
    auto patch = [&](int num) {
      int p = 0;
      for (int i = 0; i < maximumBit; ++i) {
        // 原来的为0，我就给你补上，顺便我记一下功劳
        if ((num & (1 << i)) == 0) {
          p |= (1 << i);
        }
      }
      return p;
    };
    int total = 0;
    for (auto n : nums) {
      total ^= n;
    }
    vector<int> ret;
    ret.push_back(patch(total));

    for (int i = nums.size() - 1; i > 0; i--) {
      // 向后退的时候加上这个元素，用了两次等于没用
      total ^= nums[i];
      ret.push_back(patch(total));
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{0, 1, 1, 3};
  so.getMaximumXor(input, 2);
}
