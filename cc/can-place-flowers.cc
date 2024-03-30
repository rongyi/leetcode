// http://leetcode.com/problems/can-place-flowers/description/

#include "xxx.hpp"
class Solution {
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int target) {
    int cnt = 0;
    for (int i = 0; i < flowerbed.size(); i++) {
      if (flowerbed[i] == 0) {
        if ((i == 0 || flowerbed[i - 1] == 0) &&
            (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
          cnt += 1;
          flowerbed[i] = 1;
        }
      }
    }
    return cnt >= target;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 0, 0, 0, 1, 0, 1};
  so.canPlaceFlowers(input, 1);
}
