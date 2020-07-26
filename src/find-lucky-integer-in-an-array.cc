// http://leetcode.com/problems/find-lucky-integer-in-an-array/description/
#include "xxx.h"

class Solution {
public:
  int findLucky(vector<int> &arr) {
    map<int, int> count;
    for (auto &num : arr) {
      ++count[num];
    }

    for (auto it = count.rbegin(); it != count.rend(); ++it) {
      if (it->first == it->second) {
        return it->first;
      }
    }

    return -1;
  }
};
