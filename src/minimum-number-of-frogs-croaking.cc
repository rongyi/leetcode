// http://leetcode.com/problems/minimum-number-of-frogs-croaking/description/
#include "xxx.h"

class Solution {
public:
  // think from jump over croak转轮
  int minNumberOfFrogs(string cs) {
    vector<int> circle(5, 0);
    for (auto c : cs) {
      switch (c) {
      case 'c':
        if (circle[4] > 0) {
          circle[4]--;
        }
        circle[0]++;
        break;
      case 'r':
        if (circle[0] <= 0) {
          return -1;
        }
        circle[0]--;
        circle[1]++;
        break;
      case 'o':
        if (circle[1] <= 0) {
          return -1;
        }
        circle[1]--;
        circle[2]++;
        break;
      case 'a':
        if (circle[2] <= 0) {
          return -1;
        }
        circle[2]--;
        circle[3]++;
        break;
      case 'k':
        if (circle[3] <= 0) {
          return -1;
        }
        circle[3]--;
        circle[4]++;
        break;
      default:
        return -1;
      }
    }
    // all previous should be no frog
    for (int i = 0; i < 4; ++i) {
      if (circle[i] != 0) {
        return -1;
      }
    }

    return circle[4];
  }
};
