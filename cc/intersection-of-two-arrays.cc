// http://leetcode.com/problems/intersection-of-two-arrays/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> s1;
    unordered_set<int> s2;

    for (auto i : nums1) {
      s1.insert(i);
    }
    for (auto i : nums2) {
      s2.insert(i);
    }

    vector<int> ret;
    // intersection
    for (auto k : s1) {
      if (s2.find(k) != s2.end()) {
        ret.push_back(k);
      }
    }
    return ret;
  }
};
