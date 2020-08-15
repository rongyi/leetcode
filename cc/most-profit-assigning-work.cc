// http://leetcode.com/problems/most-profit-assigning-work/description/
#include "xxx.h"

class Solution {
public:
  int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit,
                          vector<int> &worker) {
    const int n = difficulty.size();
    vector<pair<int, int>> difit;
    for (int i = 0; i < n; i++) {
      difit.push_back({difficulty[i], profit[i]});
    }

    sort(difit.begin(), difit.end());
    sort(worker.begin(), worker.end());

    int ret = 0;
    int i = 0;
    int maxp = 0;
    // 计算这个哥们在他能力范围内的最赚钱的那个工作，
    // 不一定是最难得那个
    for (auto w : worker) {
      while (i < n && w >= difit[i].first) {
        maxp = max(maxp, difit[i++].second);
      }
      ret += maxp;
    }

    return ret;
  }
};

int main() {
  // Solution so;
  vector<int> input{2, 4, 6, 8, 10};
  cout << (lower_bound(input.begin(), input.end(), 12) == input.end()) << endl;
}
