// https://leetcode.com/problems/count-of-integers/
#include "xxx.hpp"

class Solution {
public:
  int count(string num1, string num2, int min_sum, int max_sum) {
    memset(dp_, -1, sizeof(dp_));
    int sz1 = num1.size();
    int sz2 = num2.size();
    num1 = string(sz2 - sz1, '0') + num1;

    int prefix_max = dfs(0, 1, 1, max_sum, num1, num2);
    int prefix_min = dfs(0, 1, 1, min_sum - 1, num1, num2);

    return (prefix_max - prefix_min + mod_) % mod_;
  }

private:
  // is_lowest / is_highest indicate postion pos
  // is lowest or highest
  // so fancy for this two flag
  int dfs(int pos, bool is_lowest, bool is_highest, int sum, string &num1,
          string &num2) {
    if (sum < 0) {
      return 0;
    }
    if (pos == num2.size()) {
      return 1;
    }
    if (dp_[pos][is_lowest][is_highest][sum] != -1) {
      return dp_[pos][is_lowest][is_highest][sum];
    }
    // current enumeration start
    int low = is_lowest ? num1[pos] - '0' : 0;
    // enumeration end
    int high = is_highest ? num2[pos] - '0' : 9;
    int cnt = 0;
    for (int d = low; d <= high; d++) {
      cnt = (cnt % mod_ + dfs(pos + 1, is_lowest & (d == low),
                              is_highest & (d == high), sum - d, num1, num2) %
                              mod_) %
            mod_;
    }

    return dp_[pos][is_lowest][is_highest][sum] = cnt;
  }

private:
  int mod_ = 1e9 + 7;
  int dp_[23][2][2][401];
};
