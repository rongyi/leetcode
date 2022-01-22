// http://leetcode.com/problems/subarray-sum-equals-k/description/
#include "xxx.hpp"

class Solution {
public:
  // naiive method still pass the test
  int subarraySum(vector<int> &nums, int k) {
    const int n = nums.size();
    vector<int> sum(n + 1, 0);
    // put range sum to sum[1 ... n]
    for (int i = 0; i < n; i++) {
      sum[i + 1] = nums[i] + sum[i];
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
      // 1个也算range
      for (int j = i; j < n; j++) {
        int range = sum[j + 1] - sum[i];
        if (range == k) {
          ++ret;
        }
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 2, 3};
  auto ret = so.subarraySum(input, 3);
  cout << ret << endl;
}
