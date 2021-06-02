// http://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/description/
#include "xxx.h"

class Solution {
public:
  // 看图
  // https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/discuss/987607/O(n)-explanation-with-picture
  int minMoves(vector<int> &nums, int k) {
    const int n = nums.size();
    vector<int> ones;
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 1) {
        ones.push_back(i);
      }
    }
    vector<long> prefix(n + 1, 0);
    int ret = numeric_limits<int>::max();
    // 左右两个pointer
    int i = 0;
    for (int j = 0; j < ones.size(); ++j) {
      prefix[j + 1] = prefix[j] + ones[j];
      // 总共个数还没有k个
      if (j + 1 < k) {
        continue;
      }
      int mid = i + (j - i) / 2;
      int move = 0;
      int save = 0;
      // 奇数场景
      if (k % 2) {
        move = prefix[j + 1] - prefix[mid + 1] - prefix[mid] + prefix[i];
        save = (mid - i + 1) * (mid - i); // radius * (radius + 1)
      } else {
        // 图里多减一个mid，其实就是左边的prefix右边界大一个
        move = prefix[j + 1] - prefix[mid + 1] - prefix[mid + 1] + prefix[i];
        // (r + 1) * r + (r + 1)  ==> (r + 1)(r + 1)
        save = (mid - i + 1) * (mid - i + 1);
      }

      ret = min(ret, move - save);
      i++;
    }

    return ret;
  }
};
