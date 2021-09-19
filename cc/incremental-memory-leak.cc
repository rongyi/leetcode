// http://leetcode.com/problems/incremental-memory-leak/description/
#include "xxx.h"

class Solution {
public:
  vector<int> memLeak(int memory1, int memory2) {
    int round = 1;
    while ((memory1 >= round) || (memory2 >= round)) {
      // take chunk from the largest
      if (memory1 >= memory2) {
        memory1 -= round;
      } else {
        memory2 -= round;
      }
      round++;
    }

    return {round, memory1, memory2};
  }
};

int main() {
  Solution so;
  so.memLeak(2, 2);
}
