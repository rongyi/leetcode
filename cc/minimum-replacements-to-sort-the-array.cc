// https://leetcode.com/problems/minimum-replacements-to-sort-the-array/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/minimum-replacements-to-sort-the-array/discuss/2388098/C%2B%2B-Java-or-Google-Interview-Question-or-O(N)
  long long minimumReplacement(vector<int> &nums) {
    int sz = nums.size();
    long long ret = 0;
    long long prev = nums[sz - 1];
    for (int i = sz - 2; i >= 0; --i) {
      int scattered_nums = nums[i] / prev;
      if ((nums[i] % prev) != 0) {
        scattered_nums++;
        prev = nums[i] / scattered_nums;
      }

      ret += scattered_nums - 1;
    }

    return ret;
  }
};
