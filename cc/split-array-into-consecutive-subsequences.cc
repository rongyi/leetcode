// http://leetcode.com/problems/split-array-into-consecutive-subsequences/description/
#include "xxx.hpp"

class Solution {
public:
  bool isPossible(vector<int> &nums) {
    unordered_map<int, int> count;
    for (auto num : nums) {
      count[num]++;
    }
    // tail标记的是以i结尾的至少三连的数列的个数
    unordered_map<int, int> tail;
    for (auto num : nums) {
      if (count[num] <= 0) {
        continue;
      }
      count[num]--;
      // 能不能续上去的意思能续上
      if (tail[num - 1] > 0) {
        // 能续上为什么要减？
        // e.g. 11223344
        // 走到4的时候消耗掉一个队列就要减一下，第二个4的时候好判断
        tail[num - 1]--;
        tail[num]++;
      } else if (count[num + 1] > 0 && count[num + 2] > 0) {
        count[num + 1]--;
        count[num + 2]--;
        tail[num + 2]++;
      } else {
        return false;
      }
    }
    return true;
  }
};
