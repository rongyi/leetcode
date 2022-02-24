// https://leetcode.com/problems/sum-of-subarray-ranges/
#include "xxx.hpp"

class SolutionBruteForce {
public:
  // O(n^2) can pass
  long long subArrayRanges(vector<int> &nums) {
    int sz = nums.size();
    long long sum = 0;

    for (int i = 0; i < sz; ++i) {
      int cur_max = nums[i];
      int cur_min = nums[i];
      for (int j = i + 1; j < sz; ++j) {
        cur_max = max(cur_max, nums[j]);
        cur_min = min(cur_min, nums[j]);
        sum += (cur_max - cur_min);
      }
    }

    return sum;
  }
};

// still need to ref this:
// https://leetcode.com/problems/sum-of-subarray-minimums/discuss/178876/stack-solution-with-very-detailed-explanation-step-by-step
class Solution {
public:
  long long subArrayRanges(vector<int> &nums) {
    long long ret = 0;
    int sz = nums.size();
    // pushed index, not value
    stack<int> s;
    for (int i = 0; i <= sz; ++i) {
      // When an element i is smaller than the element j on the top of the
      // stack, we have i - j larger elements after j. We pop element j from the
      // stack, and now a smaller element k is on top. So, we have j - k larger
      // elements before j. Thus, the sum of corresponding subarrays is
      // (i - j) * (j - k) * n[j].
      while (!s.empty() && nums[s.top()] > (i == sz ? -2e9 : nums[i])) {
        int j = s.top();
        s.pop();
        int k = s.empty() ? -1 : s.top();
        ret -= (long long)nums[j] * (i - j) * (j - k);
      }
      // nums[i] is the lowest in range
      s.push(i);
    }

    s = stack<int>();
    for (int i = 0; i <= sz; ++i) {
      while (!s.empty() && nums[s.top()] < (i == sz ? 2e9 : nums[i])) {
        int j = s.top();
        s.pop();
        int k = s.empty() ? -1 : s.top();
        ret += (long long)nums[j] * (i - j) * (j - k);
      }
      // nums[i] is the biggest in range
      s.push(i);
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{2, 9, 7, 8, 3, 4, 6, 1};
  so.subArrayRanges(input);
}
