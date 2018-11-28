// http://leetcode.com/problems/patching-array/description/
#include "simpleone.h"

class Solution {
public:
  int minPatches(vector<int> &nums, int n) {
    // miss这里描述的是利用当前节点加起来能够到达的上边界， *不包括* 这个节点
    long miss = 1;
    int i = 0;
    int ret = 0;
    while (miss <= n) {
      if (i < nums.size() && nums[i] <= miss) {
        miss += nums[i++];
      } else {
        miss += miss;
        ret++;
      }
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 7, 9, 13, 43};
  auto ret = so.minPatches(input, 100);
  cout << ret << endl;
}
