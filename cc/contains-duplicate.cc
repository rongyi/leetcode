// http://leetcode.com/problems/contains-duplicate/description/
#include "xxx.hpp"

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_set<int> s;
    for (auto i : nums) {
      // insert return value!
      if (!s.insert(i).second) {
        return true;
      }
    }

    return false;
  }
};
