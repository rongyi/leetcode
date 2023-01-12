// https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/
#include "xxx.hpp"

class Solution {
public:
  int closetTarget(vector<string> &words, string target, int startIndex) {
    int sz = words.size();
    int ret = numeric_limits<int>::max();

    for (int i = startIndex, origin = startIndex; i < sz * 2; ++i) {
      if (words[i % sz] == target) {
        ret = min(ret, i - origin);
        break;
      }
    }
    for (int i = sz + startIndex, origin = sz + startIndex; i >= 0; --i) {
      if (words[i % sz] == target) {
        ret = min(ret, origin - i);
        break;
      }
    }

    if (ret == numeric_limits<int>::max()) {
      return -1;
    }
    return ret;
  }
};
