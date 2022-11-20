// https://leetcode.com/problems/minimize-maximum-of-array/
#include "xxx.hpp"

class Solution {
public:
  // prefix sum with avg
  int minimizeArrayValue(vector<int> &nums) {
    long long ret = 0;
    long long prefix_sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      prefix_sum += nums[i];
      ret = max((prefix_sum + i) / (i + 1), ret);
    }

    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> input{3, 7, 1, 6};
  so.minimizeArrayValue(input);
  return 0;
}
