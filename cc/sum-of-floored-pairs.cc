// http://leetcode.com/problems/sum-of-floored-pairs/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/sum-of-floored-pairs/discuss/1210060/C%2B%2B-Binary-Search
  int sumOfFlooredPairs(vector<int> &nums) {
    long mod = 1e9 + 7;
    long sz = nums.size();
    long ret = 0;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < sz;) {
      long j = i + 1;
      while (j < sz && nums[j] == nums[j - 1]) {
        ++j;
      }
      // j stop at the fist non nums[i]
      long dup = j - i;
      ret = (ret + dup * dup % mod) % mod;
      while (j < sz) {
        // 当前值
        long div = nums[j] / nums[i];
        // 上边界
        long bound = nums[i] * (div + 1);

        // [j , next) 除都等于 div
        long next = lower_bound(nums.begin(), nums.end(), bound) - nums.begin();
        // 这公式很赞
        ret = (ret + (next - j) * div % mod * dup % mod) % mod;

        j = next;
      }

      i += dup;
    }

    return ret;
  }
};

int main() {
  int sum = 0;
  vector<int> input{1, 7, 7};
  for (int i = 0; i < input.size(); ++i) {
    for (int j = 0; j < input.size(); ++j) {
      sum += input[i] / input[j];
    }
  }
  cout << sum << endl;
}
