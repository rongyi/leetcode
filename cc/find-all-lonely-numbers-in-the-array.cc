// https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/
#include "xxx.hpp"

class Solution {
public:
  // just do as they say
  vector<int> findLonely(vector<int> &nums) {
    map<int, int> count;
    for (auto num : nums) {
      count[num]++;
    }
    vector<int> ret;
    for (auto num : nums) {
      if (count[num] == 1 && count.find(num + 1) == count.end() &&
          count.find(num - 1) == count.end()) {
        ret.push_back(num);
      }
    }

    return ret;
  }
};
