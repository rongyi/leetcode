// http://leetcode.com/problems/frequency-of-the-most-frequent-element/description/
#include "xxx.h"

class Solution {
public:
  int maxFrequency(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    const int n = nums.size();
    long long ret = 1;
    long long sum = 0;
    long long i = 0;
    // sliding window
    for (int j = 0; j < n; ++j) {
      sum += nums[j];
      while (i < j && (j - i + 1) * nums[j] - sum > k) {
        sum -= nums[i];
        i++;
      }
      ret = max(ret, j - i + 1);
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{3, 9, 6};
  cout << so.maxFrequency(input, 2) << endl;
}
