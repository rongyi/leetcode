// http://leetcode.com/problems/move-zeroes/description/
#include "xxx.h"

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    const int n = nums.size();
    // 简单讲就是不是零的都移动到前面，然后后面所有内容清空为0
    int start = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] != 0) {
        nums[start++] = nums[i];
      }
    }
    fill(nums.begin() + start, nums.end(), 0);
  }
};

int main() {
  Solution so;
  vector<int> input{0, 1, 0, 3, 12};
  so.moveZeroes(input);
  for (auto i : input) {
    cout << i << " ";
  }
  cout << endl;
}
