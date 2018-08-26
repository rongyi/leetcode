// http://leetcode.com/problems/k-th-smallest-prime-fraction/description/
#include "one.h"

class Solution {
public:
  // [1, 7, 23, 29, 47]，那么有：
  // 1/47   < 1/29    < 1/23 < 1/7
  // 7/47   < 7/29    < 7/23
  // 23/47  < 23/29
  // 29/47
  // 规律： 每一列递增，每一行递增
  vector<int> kthSmallestPrimeFraction(vector<int> &A, int K) {
    priority_queue<fraction, vector<fraction>, greater<fraction>> pq;
    const int n = A.size();
    // 先插入第一列
    for (int i = 0; i < n - 1; ++i) {
      pq.push({double(A[i]) / A.back(), i, n - 1});
    }

    for (int i = 0; i < K - 1; i++) {
      auto cur = pq.top();
      // 为什么要pop？
      // 每一列只允许有一个值存在，为什么允许一个值存在？因为不弹出，结果就是第一行总是最先，这不符合要求你
      // 类似让子弹飞中的那句台词：
      // 人埋在哪，事情就发生在哪，事情发生在哪，人就埋在哪
      // 弹出来是哪一行，最小值的序列就只能发生在那行
      pq.pop();
      --cur.demoninator_;
      pq.push({double(A[cur.numerator_]) / A[cur.demoninator_], cur.numerator_,
               cur.demoninator_});
    }
    return {A[pq.top().numerator_], A[pq.top().demoninator_]};
  }

private:
  struct fraction {
    double f_;
    int numerator_;
    int demoninator_;
    bool operator<(fraction other) const { return f_ < other.f_; }
    bool operator>(fraction other) const { return f_ > other.f_; }
  };
};


int main() {
  Solution so;

  // [1, 7, 23, 29, 47]，那么有：
  vector<int> input{1, 7, 23, 29, 47};
  auto ret = so.kthSmallestPrimeFraction(input, 2);
  cout << ret[0] << ":" <<  ret[1] << endl;
}
