// http://leetcode.com/problems/patching-array/description/
#include "simpleone.h"

class Solution {
public:
  int minPatches(vector<int> &nums, int n) {
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
