// http://leetcode.com/problems/maximize-grid-happiness/description/
#include "xxx.h"

class Solution {
public:
  int getMaxGridHappiness(int m, int n, int introvertsCount,
                          int extrovertsCount) {
    memset(cache_, -1, sizeof(cache_));

    return recur(m, n, 0, 0, introvertsCount, extrovertsCount, 0);
  }

private:
  int recur(int m, int n, int x, int y, int icount, int ecount, int prevn) {
    if (y == n) {
      y = 0;
      x++;
    }

    if (icount == 0 && ecount == 0) {
      return 0;
    }

    if (x == m) {
      return 0;
    }
    if (cache_[x][y][icount][ecount][prevn] != -1) {
      return cache_[x][y][icount][ecount][prevn];
    }
    // 1. leave the cell empty
    // 0: empty, 1: intro, 2: extro
    int ret = recur(m, n, x, y + 1, icount, ecount, shiftWith(prevn, 0));

    int up = getVal(prevn, n - 1);
    int left = getVal(prevn, 0);

    if (icount > 0) {
      int tmp = prevn;
      prevn = shiftWith(prevn, 1);
      int add = 120;
      if (x - 1 >= 0 && up != 0) {
        add -= 30; // 内向遇到人了
        if (up == 1) {
          add -= 30; // 对方也是内向
        } else {
          add += 20; // 对方外向
        }
      }
      if (y - 1 >= 0 && left != 0) {
        add -= 30;
        if (left == 1) {
          add -= 30; // 对方也是内向
        } else {
          add += 20; // 对方外向
        }
      }

      ret = max(ret, recur(m, n, x, y + 1, icount - 1, ecount, prevn) + add);

      prevn = tmp;
    }

    if (ecount > 0) {
      int tmp = prevn;
      prevn = shiftWith(prevn, 2);
      int add = 40;
      if (x - 1 >= 0 && up != 0) {
        add += 20;
        if (up == 1) {
          add -= 30;
        } else {
          add += 20;
        }
      }
      if (y - 1 >= 0 && left != 0) {
        add += 20;
        if (left == 1) {
          add -= 30;
        } else {
          add += 20;
        }
      }

      ret = max(ret, recur(m, n, x, y + 1, icount, ecount - 1, prevn) + add);
      prevn = tmp;
    }

    cache_[x][y][icount][ecount][prevn] = ret;

    return ret;
  }
  // 3进制的左移加新进的一位，然后总共5位，高位截取掉
  int shiftWith(int prev, int cur) { return (prev * 3 + cur) % 243; }

  int getVal(int cur, int i) {
    cur /= (int)pow(3, i);
    return cur % 3;
  }

private:
  int cache_[6][6][7][7][243];
};

int main() {
  Solution so;
  int ret = so.getMaxGridHappiness(5, 4, 4, 3);
  cout << ret << endl;
}
