// http://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/description/
#include "xxx.h"

class Solution {
public:
  int minElements(vector<int> &nums, int limit, int goal) {
    long sum = accumulate(nums.begin(), nums.end(), 0l);
    long diff = abs(sum - goal);
    return (diff + limit - 1) / limit;
  }
};
