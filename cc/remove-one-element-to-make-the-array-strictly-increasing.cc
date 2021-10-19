// http://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/description/
#include "xxx.h"
class Solution {
public:
  bool canBeIncreasing(vector<int> &nums) {
    int sz = nums.size();
    int i = 1;
    for (; i < sz; ++i) {
      if (nums[i] <= nums[i - 1]) {
        break;
      }
    }
    // already is strictly increasing
    // or the last numer is not valid, we just drop this number
    if (i >= sz - 1) {
      return true;
    }

    // have no choice
    // check this
    // 1 2 10 5 7
    //        i at here
    // either we get 1 2 5 7
    // or 1 2 10 7
    // we need to check i - 1 vs i + 1 (delete number at i)
    // or i vs i + 1 (delete number before i) also need to check i - 2 vs i
    // e.g 2 3 1 2, when we delete 3 we get 2 1 2, this is still invalid
    // because nums[i] <= nums[i - 2]
    if (nums[i + 1] <= nums[i - 1] &&
        (nums[i + 1] <= nums[i] || (i > 1 && nums[i] <= nums[i - 2]))) {
      return false;
    }

    // the rest must be strictly valid
    i += 2;
    for (; i < sz; ++i) {
      if (nums[i] <= nums[i - 1]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution so;
  vector<int> input{2, 3, 1, 2};
  so.canBeIncreasing(input);
}
