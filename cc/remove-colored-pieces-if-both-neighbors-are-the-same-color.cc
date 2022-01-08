// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
#include "xxx.h"

class Solution {
public:
  bool winnerOfGame(string colors) {
    int alice_move = 0;
    int bob_move = 0;

    int sz = colors.size();
    for (int i = 0; i < sz; ) {
      int j = i;
      auto cur = colors[i];
      while (j < sz && colors[j] == cur) {
        j++;
      }
      if (cur == 'A') {
        // e.g. AAAA alice have 2 move
        alice_move += max(0, j - i - 2);
      } else {
        // licke alice, BBBBB will have 3 move
        bob_move += max(0, j - i - 2);
      }
      i = j;
    }

    return alice_move > bob_move;
  }
};

int main() {
  Solution so;
  so.winnerOfGame("AAABABB");
}
