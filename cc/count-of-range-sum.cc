// http://leetcode.com/problems/count-of-range-sum/description/
#include "xxx.hpp"

class Solution {
public:
  int countRangeSumTLE(vector<int> &nums, int lower, int upper) {
    const int n = nums.size();
    if (n == 0) {
      return 0;
    }
    // sum[i]表示到当前i节点的和
    vector<int> sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
      sum[i + 1] = nums[i] + sum[i];
    }

    int ret = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j <= n; j++) {
        auto delta = sum[j] - sum[i];
        if (delta >= lower && delta <= upper) {
          ret++;
        }
      }
    }
    return ret;
  }

  // TODO: 别人的解法
  int mergeSort(vector<long> &sum, int lower, int upper, int low, int high) {
    if (high - low <= 1)
      return 0;
    int mid = (low + high) / 2, m = mid, n = mid, count = 0;
    count = mergeSort(sum, lower, upper, low, mid) +
            mergeSort(sum, lower, upper, mid, high);
    for (int i = low; i < mid; i++) {
      while (m < high && sum[m] - sum[i] < lower)
        m++;
      while (n < high && sum[n] - sum[i] <= upper)
        n++;
      count += n - m;
    }
    inplace_merge(sum.begin() + low, sum.begin() + mid, sum.begin() + high);
    return count;
  }

  int countRangeSum(vector<int> &nums, int lower, int upper) {
    int len = nums.size();
    vector<long> sum(len + 1, 0);
    for (int i = 0; i < len; i++)
      sum[i + 1] = sum[i] + nums[i];
    return mergeSort(sum, lower, upper, 0, len + 1);
  }
};

int main() {
  Solution so;
  vector<int> input{-2, 5, -1};
  auto ret = so.countRangeSumTLE(input, -2, 2);
  cout << ret << endl;
}
