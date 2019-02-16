// http://leetcode.com/problems/arithmetic-slices-ii-subsequence/description/
#include "xxx.h"

class Solution {
public:
  int numberOfArithmeticSlices(vector<int> &A) {
    int ret = 0;
    const int n = A.size();
    vector<unordered_map<int, int>> dp(n);
    // 2 4 6 8 10
    // j i
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        long delta = (long)A[i] - A[j];
        if (delta > numeric_limits<int>::max() ||
            delta < numeric_limits<int>::min()) {
          continue;
        }
        int diff = (int)delta;
        // ... j ... i ...
        // 先记录下 A[i] - A[j]这样的差的数列
        // i序列前面跟它值差 diff的数目前有一个，也就是j
        ++dp[i][diff];

        if (dp[j].count(diff)) {
          // j这个数字前面差为diff的等差数列的数字有几个就能构成几个
          // 类似是算后缀
          ret += dp[j][diff];
          // 为后一轮计算做准备，这里的值不参与到ret运算中
          dp[i][diff] += dp[j][diff];
        }
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{2, 4, 6, 8, 10};
  auto ret = so.numberOfArithmeticSlices(input);
  cout << ret << endl;
}
