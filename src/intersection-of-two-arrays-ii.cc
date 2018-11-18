// http://leetcode.com/problems/intersection-of-two-arrays-ii/description/
#include "simpleone.h"

class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> s1;
    unordered_set<int> s2;

    // value --> count
    unordered_map<int, int> c1;
    unordered_map<int, int> c2;

    for (auto i : nums1) {
      s1.insert(i);
      c1[i]++;
    }
    for (auto i : nums2) {
      s2.insert(i);
      c2[i]++;
    }

    vector<int> ret;
    // intersection
    for (auto k : s1) {
      if (s2.find(k) != s2.end()) {
        for (int i = 0; i < min(c1[k], c2[k]); i++) {
          ret.push_back(k);
        }
      }
    }
    return ret;
  }
};
