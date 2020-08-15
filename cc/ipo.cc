// http://leetcode.com/problems/ipo/description/
#include "xxx.h"

class Solution {
public:
  int findMaximizedCapital(int k, int w, vector<int> &profits,
                           vector<int> &captials) {
    // 大顶
    priority_queue<int> pq;

    vector<int> idx(profits.size(), 0);
    for (int i = 0; i < idx.size(); i++) {
      idx[i] = i;
    }
    sort(idx.begin(), idx.end(), [&captials](int i, int j) -> bool {
      return captials[i] < captials[j];
    });

    int i = 0;
    while (k > 0) {
      // 如果项目需要的启动资金目前我们够了(w部分够这个项目烧的)
      while (i < idx.size() && w >= captials[idx[i]]) {
        // push的是项目的盈利
        pq.push(profits[idx[i++]]);
      }
      // 一个项目都没有，歇菜
      if (pq.empty()) {
        return w;
      }
      // 由于是大顶堆，我们在一堆能开启的项目中优先找最赚钱的
      w += pq.top();
      pq.pop();
      --k;
    }

    return w;
  }
};

int main() {
  Solution so;
  vector<int> input1{1, 2, 3};
  vector<int> input2{0, 1, 1};
  auto ret = so.findMaximizedCapital(2, 0, input1, input2);
  cout << ret << endl;
}
