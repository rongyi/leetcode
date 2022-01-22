// https://leetcode.com/problems/sum-game/
#include "xxx.hpp"

class Solution {
public:
  bool sumGame(string num) {
    int n = num.size();
    // question mark in left side
    int q_count1 = 0;
    // right side
    int q_count2 = 0;
    // digit sum in left size
    int s1 = 0;
    // right side
    int s2 = 0;
    for (int i = 0; i < n / 2; ++i) {
      if (num[i] == '?') {
        q_count1++;
      } else {
        s1 += num[i] - '0';
      }
    }
    for (int i = n / 2; i < n; ++i) {
      if (num[i] == '?') {
        q_count2++;
      } else {
        s2 += num[i] - '0';
      }
    }
    // equation left side
    int s_diff = s1 - s2;
    // equation right side
    int q_diff = q_count2 - q_count1;
    // e.g. ???? == 18
    // whatever alice pick, bob just pick 9 - x
    // and the sum will be (4 / 2 *  9) == 18
    // in this case bob will always win, other than that
    // bob lose
    bool bob_win = (q_diff % 2 == 0) && (q_diff / 2 * 9 == s_diff);

    return !bob_win;
  }
};
