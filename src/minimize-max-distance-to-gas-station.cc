// http://www.lintcode.com/zh-cn/problem/minimize-max-distance-to-gas-station
#include "one.h"

// 一种贪心的做法是，找到最大的gap，插入1个station，依此类推，但很遗憾，这种贪心策略是错误的。问题的难点在于我们无法确定到底哪两个station之间需要插入station，插入几个station也无法得知。

// 换个思路，如果我们假设知道了答案会怎么样？因为知道了最大间隔，所以如果目前的两个station之间的gap没有符合最大间隔的约束，那么我们就必须添加新的station来让它们符合最大间隔的约束，这样一来，对于每个gap我们是能够求得需要添加station的个数。如果需求数<=K，说明我们还可以进一步减小最大间隔，直到需求数>K。
class Solution {
public:
  double minmaxGasDist(vector<int> &stations, int K) {
    double left = 0, right = 1e8;
    while (right - left > 1e-6) {
      double mid = left + (right - left) / 2;
      if (helper(stations, K, mid))
        right = mid;
      else
        left = mid;
    }
    return left;
  }
  bool helper(vector<int> &stations, int K, double mid) {
    int cnt = 0, n = stations.size();
    for (int i = 0; i < n - 1; ++i) {
      cnt += (stations[i + 1] - stations[i]) / mid;
    }
    return cnt <= K;
  }
};

int main() {
  Solution so;
  vector<int> input{0, 10};
  auto ret = so.minmaxGasDist(input, 1);
  cout << ret << endl;
}
