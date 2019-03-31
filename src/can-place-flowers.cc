// http://leetcode.com/problems/can-place-flowers/description/

#include "xxx.h"
class Solution {
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int target) {
    int plant = 0;
    const int n = flowerbed.size();
    int i = 0;
    while (i < n) {
      if (flowerbed[i] == 0) {
        int j = i;
        while (j < n && flowerbed[j] == 0) {
          j++;
        }
        // flowerbed has no plant at all!
        if (i == 0 && j == n) {
          plant = (n + 1) / 2;
          break;
        }
        // we have start partial plant
        if (i == 0 || j == n) {
          plant += max(0, (j - i) / 2);
        } else {
          plant += max(0, (j - i - 1) / 2);
        }

        // we have middle partial plant
        // we have end section partial plant
        i = j;
      } else {
        i++;
      }
    }
    return plant >= target;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 0, 0, 0, 1, 0, 1};
  so.canPlaceFlowers(input, 1);
}
