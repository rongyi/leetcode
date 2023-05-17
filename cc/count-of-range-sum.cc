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

  // Recall count smaller number after self where we encountered the problem

  // count[i] = count of nums[j] - nums[i] < 0 with j > i
  // Here, after we did the preprocess(prefix sum S[i]), we need to solve the
  // problem count[i] = count of a <= S[j] - S[i] <= b with j > i ans =
  // sum(count[:])
  int mergeSort(vector<long> &sum, int lower, int upper, int l, int r) {
    if (r - l <= 1) {
      return 0;
    }
    int mid = (l + r) / 2;
    int m = mid;
    int n = mid;
    int count = 0;

    // First of all, we get the sum array. Then, we divide the array by halves.
    // The range can exist inside the first and second half, it can also exist
    // across the first and second half. Then for a range [start, end], the
    // recursion becomes:

    // in the first half + # in the second half + # across the first and second
    // half. How to get the # in the first and second half? The above recursion
    // still applies!

    // Then, the question becomes how to count the # across the first and second
    // half. What happens the first half and second half are sorted after we
    // count the # inside them? It becomes quite simple to get the cross result.
    // It becomes a two pointer question.

    // The use a low pointer to get the first index that satisfies
    // sum[low] - sum[i] >= lower, and get the last index that satisfies
    // sum[high] - sum[i] >= upper.
    // The # of cross result that can be formed
    // with i as the left index is upper - lower. Since the first half is
    // sorted, sum[i + 1] >= sum[i], then, low and high do not need to go back.
    // Therefore, it is O(N) operation.
    count = mergeSort(sum, lower, upper, l, mid) +
            mergeSort(sum, lower, upper, mid, r);
    for (int i = l; i < mid; i++) {
      // find first one >= lower
      while (m < r && sum[m] - sum[i] < lower) {
        m++;
      }
      // find first one > upper
      while (n < r && sum[n] - sum[i] <= upper) {
        n++;
      }
      count += n - m;
    }
    inplace_merge(sum.begin() + l, sum.begin() + mid, sum.begin() + r);

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

  auto ret = so.countRangeSum(input, -2, 2);

  cout << ret << endl;
}
