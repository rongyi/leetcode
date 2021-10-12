// http://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/description/
#include "xxx.h"

class Solution {
public:
  int chalkReplacer(vector<int> &chalk, int k) {
    long long sum = accumulate(chalk.begin(), chalk.end(), 0ll);
    // cut the round, only left the last round
    long long kk = (long long)k % sum;

    int sz = chalk.size();
    for (int i = 0; i < sz; ++i) {
      if (kk < chalk[i]) {
        return i;
      }
      kk -= chalk[i];
    }

    // imposibble reach, just let compiler shutup
    return 0;
  }
};
