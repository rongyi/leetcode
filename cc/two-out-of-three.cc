// https://leetcode.com/problems/two-out-of-three/
#include "xxx.hpp"
class Solution {
public:
  vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2,
      vector<int> &nums3) {
    set<int> s1(nums1.begin(), nums1.end());
    set<int> s2(nums2.begin(), nums2.end());
    set<int> s3(nums3.begin(), nums3.end());

    set<int> ret;

    for (auto &k : s1) {
      if (s2.count(k) || s3.count(k)) {
        ret.insert(k);
      }
    }
    for (auto &k : s2) {
      if (s3.count(k)) {
        ret.insert(k);
      }
    }

    return vector<int>(ret.begin(), ret.end());
  }
};

