// http://leetcode.com/problems/fruit-into-baskets/description/
#include "xxx.h"

class Solution {
public:
  int totalFruit(vector<int> &tree) {
    int ret = 0;
    int cur_max = 0;
    int lastFruit = -1;
    int secondLastFruit = -1;
    int lastFruitCount = 0;

    for (auto fruit : tree) {
      if (fruit == lastFruit || fruit == secondLastFruit) {
        cur_max++;
      } else {
        cur_max = lastFruitCount + 1;
      }

      if (fruit == lastFruit) {
        lastFruitCount++;
      } else {
        lastFruitCount = 1;
      }

      if (fruit != lastFruit) {
        secondLastFruit = lastFruit;
        lastFruit = fruit;
      }
      ret = max(ret, cur_max);
    }

    return ret;
  }
};
