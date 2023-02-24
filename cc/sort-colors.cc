// http://leetcode.com/problems/sort-colors/description/
#include "xxx.hpp"

class Solution {
public:
  void sortColors(vector<int> &nums) {
    int sz = nums.size();
    // next valid pos for color red
    int red = 0;
    // same for color blue
    int blue = sz - 1;

    for (int i = 0; i <= blue;) {
      if (nums[i] == 0) {
        swap(nums[i++], nums[red++]);
      } else if (nums[i] == 2) {
        swap(nums[i], nums[blue]);
        blue--;
      } else {
        i++;
      }
    }
  }
};

