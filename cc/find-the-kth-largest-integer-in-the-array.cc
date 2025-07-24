// http://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/description/
#include "xxx.hpp"

class Solution {
public:
  string kthLargestNumber(vector<string> &snums, int k) {
    // don't use stoi, the string is too fucking long
    sort(snums.begin(), snums.end(), [](auto l, auto r) {
      // longer is bigger
      if (l.size() != r.size()) {
        return l.size() < r.size();
      }
      // same  length, just compare
      return l < r;
    });

    return snums[snums.size() - k];
  }
};
