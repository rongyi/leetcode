// http://leetcode.com/problems/palindrome-linked-list/description/
#include "simpleone.h"

class Solution {
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    // total
    int sum = (C - A) * (D - B) + (G - E) * (H - F);
    // no intersection，在四个方向上转一圈
    if (E >= C || F >= D || B >= H || A >= G)
      return sum;
    // 如果重叠的话，计算重叠部分面积就是四个横坐标中中间那两个和四个纵坐标中间那两个。
    vector<int> x{A, C, E, G};
    sort(x.begin(), x.end());
    vector<int> y{B, D, F, H};
    sort(y.begin(), y.end());

    return sum - (x[2] - x[1]) * (y[2] - y[1]);
  }
};
int main() {
  Solution so;
  auto ret = so.computeArea(-5, -3, 5, 0, -3, -3, 3, 3);
  cout << ret << endl;
}
