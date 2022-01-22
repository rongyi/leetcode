// http://leetcode.com/problems/number-of-different-subsequences-gcds/description/
#include "xxx.hpp"

class Solution {
public:
  int countDifferentSubsequenceGCDs(vector<int> &nums) {
    int ret = 0;
    // 一个数列的gcd不可能大于数列中的最大值
    int max_num = numeric_limits<int>::min();
    const int n = nums.size();
    int b[200001] = {0};

    for (int i = 0; i < n; ++i) {
      max_num = max(max_num, nums[i]);
      b[nums[i]] = 1;
    }

    // 一个数列的gcd随着数组的变多将会递减
    for (int g = 1; g <= max_num; ++g) {
      int cur_gcd = 0;

      for (int j = g; j <= max_num; j += g) {
        if (b[j] == 1) {
          // e.g.
          // g 为4
          // 出现的numer为 8 16 24 36 ==> gcd 为 4
          cur_gcd = __gcd(cur_gcd, j);
        }

        // 最终会降到这里，那么g这个value可以形成一个subsequence
        if (cur_gcd == g) {
          ret++;
          break;
        }
      }
    }

    return ret;
  }
};

int main() {
  cout << __gcd(0, 10) << endl;
}
