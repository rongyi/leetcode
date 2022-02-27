// https://leetcode.com/problems/watering-plants-ii/
#include "xxx.hpp"

class Solution {
public:
  int minimumRefill(vector<int> &plants, int capacityA, int capacityB) {
    int sz = plants.size();
    int refill_count = 0;

    int i = 0;
    int j = sz - 1;
    int alice_cur = capacityA;
    int bob_cur = capacityB;

    // ignore the time, just watering it one by one.
    while (i < j) {
      if (plants[i] > alice_cur) {
        refill_count += 1;
        alice_cur = capacityA;
      }
      if (plants[j] > bob_cur) {
        refill_count += 1;
        bob_cur = capacityB;
      }
      alice_cur -= plants[i];
      bob_cur -= plants[j];

      i++;
      j--;
    }

    // check the middle plant
    if (sz & 1) {
      if (plants[i] > alice_cur && plants[i] > bob_cur) {
        refill_count += 1;
      }
    }

    return refill_count;
  }
};
