// http://leetcode.com/problems/maximize-sum-of-array-after-k-negations/description/
#include "xxx.hpp"

class Solution {
public:
  int largestSumAfterKNegations(vector<int> &A, int K) {
    int sum_pos = 0;
    vector<int> negs;
    int minabs = numeric_limits<int>::max();
    for (auto num : A) {
      minabs = min(abs(num), minabs);
      if (num >= 0) {
        sum_pos += num;
      } else {
        negs.push_back(num);
      }
    }
    const int n = negs.size();
    // 负数正好全部被掀翻
    if (n == K) {
      return sum_pos - accumulate(negs.begin(), negs.end(), 0);
    }
    // K剩余
    if (n < K) {
      int left_flips = K - n;
      // 剩下奇数
      if (left_flips & 0x1) {
        return sum_pos - accumulate(negs.begin(), negs.end(), 0) - minabs * 2;
      }
      // 如果有0在那把剩余的操作全部应用到这个0身上
      return sum_pos - accumulate(negs.begin(), negs.end(), 0);
    }
    // n > K 剩余
    sort(negs.begin(), negs.end());
    for (int i = 0; i < K; i++) {
      negs[i] *= -1;
    }
    return accumulate(negs.begin(), negs.end(), 0) + sum_pos;
  }
};

int main() {
  Solution so;
  vector<int> input{4, 2, 3};
  auto ret = so.largestSumAfterKNegations(input, 1);
  cout << ret << endl;
}
