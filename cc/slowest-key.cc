// http://leetcode.com/problems/slowest-key/description/
#include "xxx.h"

class Solution {
public:
  char slowestKey(vector<int> &releaseTimes, string keysPressed) {
    int max_interval = releaseTimes[0];
    char max_key = keysPressed[0];

    for (int i = 1; i < keysPressed.size(); ++i) {
      auto cur = releaseTimes[i] - releaseTimes[i - 1];
      if (cur > max_interval) {
        max_interval = cur;
        max_key = keysPressed[i];
      } else if (cur == max_interval) {
        max_key = max(max_key, keysPressed[i]);
      }
    }

    return max_key;
  }
};
