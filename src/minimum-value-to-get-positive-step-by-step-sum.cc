// http://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/description/
#include "xxx.h"

class Solution {
public:
  int minStartValue(vector<int> &nums) {
    int pre_sum = nums[0];
    int min_sum = pre_sum;
    for (int i = 1; i < nums.size(); ++i) {
      pre_sum += nums[i];
      min_sum = min(min_sum, pre_sum);
    }
    if (min_sum >= 1) {
      // must be a postive
      return 1;
    }
    return 1 + abs(min_sum);
  }
};

int main() {
  vector<int> input = {-3, 2, -3, 4, 2};
  Solution so;
  so.minStartValue(input);
}
