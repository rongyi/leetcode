// http://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/description/
#include "xxx.h"

class Solution {
public:
  int minimumDistance(string word, int pos = 0, char left = 26,
                      char right = 26) {
    if (pos >= word.size()) {
      return 0;
    }
    if (dp_[left][right][pos] == 0) {
      auto to = word[pos] - 'A';
      dp_[left][right][pos] =
          // left hand hit the current key, so left hand now landing on 'to'
          min(cost(left, to) + minimumDistance(word, pos + 1, to, right),
              // right hand hit the current key, so right hand
              // now landing on 'to'
              cost(right, to) + minimumDistance(word, pos + 1, left, to)) +
          1;
    }

    return dp_[left][right][pos] - 1;
  }

private:
  int cost(char from, char to) {
    if (from == 26) {
      return 0;
    }
    return abs(from / 6 - to / 6) + abs(from % 6 - to % 6);
  }

private:
  int dp_[27][27][301];
};
