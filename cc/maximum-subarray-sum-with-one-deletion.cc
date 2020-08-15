// http://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/discuss/377507/c%2B%2B-dp-with-constant-space
  int maximumSum(vector<int> &arr) {
    const int n = arr.size();
    if (n == 1) {
      return arr[0];
    }
    int ret = 0;
    // dropped means max subarry of end with current index which has dropped one
    // elements end with i
    int dropped = max(arr[0], arr[1]);
    // 要么arr[1]新开，要么就是到当前的总共的和
    int not_dropped = max(arr[1], arr[0] + arr[1]);
    ret = max(dropped, not_dropped);

    for (int i = 2; i < n; ++i) {
      dropped = max(not_dropped, arr[i] + dropped);
      not_dropped = max(not_dropped + arr[i], arr[i]);
      ret = max(ret, max(dropped, not_dropped));
    }

    return ret;
  }
};
