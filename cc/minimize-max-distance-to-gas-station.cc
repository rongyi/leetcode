// http://www.lintcode.com/zh-cn/problem/minimize-max-distance-to-gas-station
#include "xxx.h"

// 换个思路，如果我们假设知道了答案会怎么样？因为知道了最大间隔，
// 所以如果目前的两个station之间的gap没有符合最大间隔的约束，
// 那么我们就必须添加新的station来让它们符合最大间隔的约束，
// 这样一来，对于每个gap我们是能够求得需要添加station的个数。
// 如果需求数<=K，说明我们还可以进一步减小最大间隔，直到需求数>K。
class Solution {
public:
  double minmaxGasDist(vector<int> &stations, int K) {
    const int n = stations.size();
    vector<int> gaps;
    for (int i = 0; i < n - 1; ++i) {
      gaps.push_back(stations[i + 1] - stations[i]);
    }

    double left = 0, right = 1e8;
    while (right - left > 1e-6) {
      double mid = left + (right - left) / 2;
      if (helper(gaps, K, mid))
        right = mid;
      else
        left = mid;
    }
    return left;
  }

private:
  // 最大间隔值是cur_gap时，需要插入多少个隔板（新的station）呢
  bool helper(vector<int> &gaps, int K, double cur_gap) {
    int cnt = 0, n = gaps.size();
    for (int i = 0; i < n; ++i) {
      cnt += int(gaps[i] / cur_gap);
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
