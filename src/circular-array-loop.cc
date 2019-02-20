// http://leetcode.com/problems/circular-array-loop/description/
#include "xxx.h"

class Solution {
public:
  bool circularArrayLoop(vector<int> &nums) {
    const int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) {
        continue;
      }
      int cur = i;
      while (true) {
        // step有可能是0哦，比如是第二块石头，从非0跳过来
        int step = nums[cur];
        // 把当前格给填了，调到这loop就loop了，不loop不管从前面哪个点
        // 跳过来都绕不起来，所以跳到我这就别跳了
        nums[cur] = 0;
        int next = (cur + step) % n;
        if (next < 0) {
          next += n;
        }
        // 方向相反或者
        if (cur == next || step * nums[next] < 0) {
          break;
        }
        if (cur != next && next == i) {
          return true;
        }
        // 继续
        cur = next;
      }
    }
    return false;
  }
};
