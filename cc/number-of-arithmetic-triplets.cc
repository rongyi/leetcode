// https://leetcode.com/problems/number-of-arithmetic-triplets/
#include "xxx.hpp"

class Solution {
public:
  int arithmeticTriplets(vector<int> &nums, int diff) {
    int ret = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int cur = nums[i];
      int mid = cur + diff;
      int right = mid + diff;
      auto midit = lower_bound(nums.begin(), nums.end(), mid);
      auto rightit = lower_bound(nums.begin(), nums.end(), right);
      if (midit != nums.end() && *midit == mid && rightit != nums.end() &&
          *rightit == right) {
        ret++;
      }
    }

    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> input{0, 1, 4, 6, 7, 10};
  so.arithmeticTriplets(input, 3);
  return 0;
}
