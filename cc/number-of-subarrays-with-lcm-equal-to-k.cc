// https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k/
#include "xxx.hpp"

class Solution {
public:
  int subarrayLCM(vector<int> &nums, int k) {
    int sz = nums.size();
    int ret = 0;
    for (int i = 0; i < sz; ++i) {
      int cur = nums[i];
      for (int j = i; j < sz && (k % nums[j]) == 0; ++j) {
        cur = lcm(cur, nums[j]);
        ret += (cur == k);
      }
    }

    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> input{3, 6, 2, 7, 1};
  so.subarrayLCM(input, 6);
  return 0;
}
