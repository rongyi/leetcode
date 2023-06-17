// https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/
#include "xxx.hpp"

class Solution {
public:
  int minNumber(vector<int> &nums1, vector<int> &nums2) {
    set<int> s1(nums1.begin(), nums1.end());
    set<int> s2(nums2.begin(), nums2.end());
    for (auto &k : s1) {
      if (s2.count(k)) {
        return k;
      }
    }

    int m1 = *min_element(nums1.begin(), nums1.end());
    int m2 = *min_element(nums2.begin(), nums2.end());

    return min(m1, m2) * 10 + max(m1, m2);
  }
};
