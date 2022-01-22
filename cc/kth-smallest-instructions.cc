// http://leetcode.com/problems/kth-smallest-instructions/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/kth-smallest-instructions/discuss/918375/C%2B%2B-Combination
  string kthSmallestPath(vector<int> &destination, int k) {
    // 最终的结果中有列有多少列就有多少个H
    // 有多少行就代表有多少个V
    int h = destination[1];
    int v = destination[0];
    int n = h + v;
    ostringstream ss;

    for (int i = 0; i < n; ++i) {
      if (h) {
        // H是排在前面的，所以先算一下，如果序列在这个组合里那么肯定要先选H
        // 不在，就代表前面这么多中情况直接去掉
        int c = comb(h - 1 + v, v);
        if (k <= c) {
          ss << 'H';
          --h;
        } else {
          k -= c;
          ss << 'V';
          --v;
        }
      } else {
        ss << 'V';
        --v;
      }
    }

    return ss.str();
  }

private:
  //  r
  // C
  //  n
  // ==> n!/(r! * (n - r)!) ==> n * (n - 1) * ... * (n - r + 1) / r!
  int comb(int n, int r) {
    long ret = 1;

    for (int i = 1, j = n - r + 1; i <= r; ++i, ++j) {
      ret = ret * j / i;
    }

    return ret;
  }
};
