// http://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
#include "xxx.hpp"

class Solution {
public:
  bool check(vector<int> &nums) {
    const int n = nums.size();
    // 断崖的下跌只能有一次
    int count = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] > nums[(i + 1) % n]) {
        count++;
      }
      if (count > 1) {
        return false;
      }
    }

    return true;
  }
  bool check1(vector<int> &nums) {
    const int n = nums.size();
    int p = 0;
    for (; p < n - 1; ++p) {
      if (nums[p] > nums[p + 1]) {
        break;
      }
    }
    p++;

    // 从这以后开始都是按顺序的了
    for (int i = 0; i < n - 1; ++i) {
      if (nums[(i + p) % n] > nums[(i + p + 1) % n]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution so;
  vector<int> input{3, 4, 5, 1, 2};
  so.check(input);
}
