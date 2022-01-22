// http://leetcode.com/problems/can-place-flowers/description/

#include "xxx.hpp"
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
        // 00001 or 10000 start or end
        // 如上，我们有四个空位放花去掉与1相邻的地方不能放，我们有三个空位 j - i
        // - 1 而三个不带限制条件所能放的最多的花的方法是 f(n) = (n + 1) / 2
        // 代入(j - i - 1 + 1) / 2 ==> (j - i) / 2
        if (i == 0 || j == n) {
          plant += max(0, (j - i) / 2);
        } else { // 分析同上,空位有 j - i - 2个
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
