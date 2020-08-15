// http://leetcode.com/problems/circular-array-loop/description/
#include "xxx.h"

class Solution {
public:
  bool circularArrayLoop(vector<int> &nums) {
    const int n = nums.size();
    // 貌似只要全是正数，或者全是负数都会始终会碰撞的
    for (auto &i : nums) {
      i %= n;
    }
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) {
        continue;
      }
      long sign = nums[i] > 0 ? 1 : -1;
      // 快慢指针的方式来解决
      // j是慢指针
      int j = i;
      // k是快指针
      int k = i;
      while (true) {
        k = getIndex(nums, k);
        if (nums[k] * sign <= 0) {
          break;
        }
        k = getIndex(nums, k);
        if (nums[k] * sign <= 0) {
          break;
        }

        i = getIndex(nums, i);
        if (i == k) {
          return true;
        }
      }
      j = i;
      while (j != k) {
        int l = j;
        j = getIndex(nums, j);
        nums[l] = 0;
      }
    }
    return false;
  }

private:
  int getIndex(vector<int> &nums, int k) {
    return (k + nums[k] + nums.size()) % nums.size();
  }
};

int main() {
  Solution so;
  vector<int> input{-1, -4, -2, -2, -1, -2};
  auto ret = so.circularArrayLoop(input);
  cout << ret << endl;
}
