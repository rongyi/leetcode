// http://leetcode.com/problems/robot-return-to-origin/description/
#include "xxx.h"

class Solution {
public:
  bool judgeCircle(string moves) {
    pair<int, int> origin{0, 0};
    for (auto step : moves) {
      switch (step) {
      case 'R':
        origin.first++;
        break;
      case 'L':
        origin.first--;
        break;
      case 'U':
        origin.second++;
        break;
      case 'D':
        origin.second--;
        break;
      }
    }

    return origin.first == 0 && origin.second == 0;
  }
};
