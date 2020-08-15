// http://leetcode.com/problems/super-washing-machines/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/super-washing-machines/discuss/99177/Very-intuitive-O(n)-solution
  int findMinMoves(vector<int> &machines) {
    const int n = machines.size();
    // 前面留一个空的，从1开始放
    vector<int> sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
      sum[i + 1] = sum[i] + machines[i];
    }

    if ((sum[n] % n) != 0) {
      return -1;
    }
    int avg = sum[n] / n;
    int ret = 0;
    for (int i = 0; i < n; i++) {
      // Think about the machine i, after we make all machines have the same
      // dresses, how many dresses will be passed through machine i?
      // Let's denote the current sum of dresses of machines [0...i-1] as
      // leftSums[i], and the current sum of dresses of machines [i+1...n-1] as
      // rightSums[i].

      // Let's denote the expected sum of dresses of machines [0...i-1] as
      // expLeft, which means after all dresses are equally distributed, the sum
      // of address in machines [0...i-1] should be expLeft. The same logic
      // applies to machines [i+1...n-1], denoted as expRight.

      // Then the above question should be clearly answered. If expLeft is
      // larger than leftSums[i], that means no matter how you move the dresses,
      // there will be at least expLeft - leftSums[i] dresses being moved to
      // left of machine i, which means pass through machine i. For the right
      // machines of machine i, the logic remains the same. So we could conclude
      // that the minimum dresses passed through machine i will be:

      // left = expLeft > leftSums[i] ? expLeft - leftSums[i] : 0;
      // right = expRight > rightSums[i] ? expRight - rightSums[i] : 0;
      // total = left + right;

      int exp_left = i * avg;
      int exp_right = (n - i - 1) * avg;
      int left = 0;
      int right = 0;
      int right_sum = sum[n] - sum[i] - machines[i];
      if (exp_left > sum[i]) {
        left = exp_left - sum[i];
      }
      if (exp_right > right_sum) {
        right = exp_right - right_sum;
      }
      ret = max(ret, left + right);
    }

    return ret;
  }
};
