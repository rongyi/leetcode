// https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/
#include "one.h"
class Solution {
public:
  // return the k-th smallest distance among all the pairs
  int smallestDistancePairBruteForce(vector<int> &nums, int k) {
    // 总共值区间在一百万以内，那就创建这么多桶，
    // 然后差值往桶里丢，统计出来之后
    // 从最小的差值往后找
    const int n = 1000000;
    vector<int> cnt(n, 0);
    const int len = nums.size();
    for (int i = 0; i < len; ++i) {
      for (int j = i + 1; j < len; ++j) {
        ++cnt[abs(nums[i] - nums[j])];
      }
    }
    for (int i = 0; i < n; i++) {
      if (cnt[i] >= k) {
        return i;
      }
      // 精彩
      k -= cnt[i];
    }
    return -1;
  }
  int smallestDistancePair(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());

    const int n = nums.size();
    int left = 0;
    int right = nums.back() - nums[0];
    // 意思是让我们来假设当前第K个值为mid，然后我们来数一数前面有多少个数呢？
    // 如果数下来恰好是第K个，那么就对了
    // 多了，那么说明真正第K个元素比我们预估的要小(我们估大发了)，那么预估的mid要往小的方向走
    // 少了，说明真正第K个元素比我们预估的要大， 预估的值(mid)往大了走
    while (left < right) {
      int mid = left + (right - left) / 2;
      int cnt = 0;
      int start = 0;
      for (int i = 0; i < n; ++i) {
        // 数前面有多少个的trick
        while (start < n && (nums[i] - nums[start] > mid)) {
          ++start;
        }
        cnt += i - start;
      }
      if (cnt < k) {
        left = mid + 1;
      } else { // 这个是前面数比K还多的情况，
        right = mid;
      }
    }
    return right;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 2, 20, 70, 10};
  auto ret = so.smallestDistancePair(input, 1);
  cout << ret << endl;
}
