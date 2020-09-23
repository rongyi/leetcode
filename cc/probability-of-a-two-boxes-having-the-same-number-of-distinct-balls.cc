// http://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/discuss/661730/C%2B%2B-Backtrack-with-explanation
  double getProbability(vector<int> &balls) {
    auto sum = accumulate(balls.begin(), balls.end(), 0);
    vector<int> a(balls.size(), 0);
    vector<int> b(balls.size(), 0);

    return dfs(balls, a, b, sum, 0, 0, 0) / perm(balls);
  }

private:
  double perm(vector<int> &A) {
    double ret = 1;
    // 这里也是很精妙
    for (int i = 0, j = 1; i < A.size(); ++i) {
      for (int k = 1; k <= A[i]; ++k, ++j) {
        // 先除防止溢出
        ret = ret * j / k;
      }
    }

    return ret;
  }

  double dfs(vector<int> &A, vector<int> &a, vector<int> &b, const int &sum,
             int cur, int sa, int sb) {
    if (sa > sum / 2 || sb > sum / 2) {
      return 0;
    }
    if (cur == A.size()) {
      int ca = 0;
      int cb = 0;
      for (int i = 0; i < A.size(); ++i) {
        ca += a[i] > 0;
      }
      for (int i = 0; i < A.size(); ++i) {
        cb += b[i] > 0;
      }
      // distint color not same
      if (ca != cb) {
        return 0;
      }

      return perm(a) * perm(b);
    }

    double ret = 0;
    for (int i = 0; i <= A[cur]; ++i) {
      a[cur] = i;
      b[cur] = A[cur] - i;
      ret += dfs(A, a, b, sum, cur + 1, sa + a[cur], sb + b[cur]);
    }

    return ret;
  }
};
