// https://leetcode.com/problems/k-radius-subarray-averages/
#include "xxx.hpp"

class Solution {
public:
  vector<int> getAverages(vector<int> &nums, int k) {
    // prefix sum will overflow, so we use sliding window instead
    vector<int> ret;
    int sz = nums.size();

    long long win_sum = 0;
    // initial valid window
    // leave last num for next sum
    for (int i = 0;
         i < min(2 * k, sz) /*note this trick, may give very large radius*/;
         ++i) {
      win_sum += nums[i];
    }

    for (int i = 0; i < sz; ++i) {
      auto l = i - k;
      auto r = i + k;
      if (l < 0 || r >= sz) {
        ret.push_back(-1);
      } else {
        win_sum += nums[i + k];
        ret.push_back(win_sum / (2 * k + 1));
        win_sum -= nums[i - k];
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{8};
  so.getAverages(input, 100000);
}
