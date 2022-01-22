// http://leetcode.com/problems/arithmetic-slices-ii-subsequence/description/
#include "xxx.hpp"

class Solution {
public:
  int numberOfArithmeticSlices(vector<int> &A) {
    int ret = 0;
    const int n = A.size();
    vector<unordered_map<int, int>> dp(n);
    // 2 4 6 8 10
    // | |
    // j i 这样的位置
    // dp[i][2] = 1 ==> 表示差为2的等差数列前面有个一个数字

    // 2 4 6 8 10
    //   | |
    //   j i 这样的位置
    // 先更新dp[i][2] = 1表示差为2的等差数列前面有一个数字，这个数字就是j上的数字
    // 然后在j的cache里也找到差为2的数字也就是上一轮的dp[1][2] = 1这个值
    // 此时说明：
    // x j i这三个index上的值能组成三个等差数列了,而且还是x有多少个(j这个cache里面的数字)
    // 答案就是多少，比如1个的时候？ x j i， 2个的时候 a b j i, b j i，为毛不把 a b j也算
    // 进去呢？因为在算j的时候已经把a b j算进去了(加到ret上了)
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
