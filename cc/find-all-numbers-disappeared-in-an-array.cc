// http://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    unordered_map<int, int> count;
    for (auto i : nums) {
      count[i]++;
    }
    vector<int> ret;
    for (int i = 1; i <= nums.size(); i++) {
      if (count.find(i) == count.end()) {
        ret.push_back(i);
      }
    }

    return ret;
  }
};
