// http://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/
#include "xxx.h"

class Solution {
public:
  int findKthNumber(int m, int n, int k) {
    int lo = 1;
    int hi = m * n;
    while (lo < hi) {
      auto mid = lo + (hi - lo) / 2;
      // count统计出来的是小于mid的个数
      int count = 0;
      int j = n;
      // 遍历每一行，找 <= mid的个数，然后汇总
      for (int i = 1; i <= m; i++) {
        while (j >= 1 && i * j > mid) {
          j--;
        }
        count += j;
      }
      if (count < k) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
    return lo;
  }

  // virtual matrix，这种会超时
  int findKthNumberTLE(int m, int n, int k) {
    using Pair = pair<int, int>;
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    // 心中的乘法表 matrix
    pq.push({1, 0});

    int ret = 0;
    while (k--) {
      auto p = pq.top();
      pq.pop();

      ret = p.first;

      int cell = p.second;
      int r = cell / n;
      int c = cell % n;

      int nextr = r + 1;
      int nextc = c + 1;
      if (c == 0 && nextr < m) {
        // 坐标都是0 indexed，所以这里补1
        // 这里再把 (nextr, c) 坐标换算成值
        pq.push({(nextr + 1) * (c + 1), nextr * n + c});
      }
      if (nextc < n) {
        // 同样把(r, nextc)坐标换算成值
        pq.push({(r + 1) * (nextc + 1), r * n + nextc});
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  auto ret = so.findKthNumber(3, 3, 5);
  cout << ret << endl;
}
