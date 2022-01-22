// https://leetcode.com/problems/couples-holding-hands/description/
#include "xxx.hpp"

class Solution {
public:
  int minSwapsCouples(vector<int> &row) {
    int ret = 0;
    const int n = row.size() / 2;
    for (int i = 0; i < n; ++i) {
      int one = row[2 * i];
      int another = mycouple(one);
      if (another == row[2 * i + 1]) {
        continue;
      }
      ++ret;
      // be a matchmaker and put couple together
      for (int j = 2 * (i + 1); j < 2 * n; ++j) {
        if (row[j] == another) {
          // 这里只把后面的couple配对，当前判断的这个配不配对已经无所谓了，因为这一对已经判断过，没必要再改回去
          // 所以这里没有row[2 * i + 1] = row[j]这个语句
          row[j] = row[2 * i + 1];
          break;
        }
      }
    }
    return ret;
  }

private:
  int mycouple(int i) {
    if (i & 1) {
      return i - 1;
    }
    return i + 1;
  }
};

int main() {
  Solution so;
  vector<int> input{5, 4, 2, 6, 3, 1, 0, 7};
  auto ret = so.minSwapsCouples(input);
  cout << ret << endl;
}
