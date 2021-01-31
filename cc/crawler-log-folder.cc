// http://leetcode.com/problems/crawler-log-folder/description/
#include "xxx.h"

class Solution {
public:
  int minOperations(vector<string> &logs) {
    int ret = 0;
    for (auto &l : logs) {
      if (l[0] != '.') {
        ret++;
      } else if (l == "../") {
        --ret;
        ret = max(ret, 0);
      }
    }
    return ret;
  }
};
