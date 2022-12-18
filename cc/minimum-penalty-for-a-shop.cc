// https://leetcode.com/problems/minimum-penalty-for-a-shop/
#include "xxx.hpp"

class Solution {
public:
  int bestClosingTime(string customers) {
    int sz = customers.size();
    vector<int> prevn(sz + 1, 0);
    vector<int> aftery(sz + 1, 0);
    vector<int> sum(sz + 1, 0);
    for (int i = 0; i < sz; ++i) {
      prevn[i + 1] = prevn[i] + (customers[i] == 'N');
      aftery[sz - i - 1] =
          aftery[sz - i - 1 + 1] + (customers[sz - i - 1] == 'Y');
    }
    sum[0] = aftery[0];
    sum[sz] = prevn[sz - 1];

    for (int i = 1; i < sz; ++i) {
      sum[i] = aftery[i] + prevn[i];
    }
    int penalty = numeric_limits<int>::max();
    int ret = -1;
    // from end to begin to get the smaller index
    // under equal condition
    for (int i = sz; i >= 0; --i) {
      if (sum[i] <= penalty) {
        penalty = sum[i];
        ret = i;
      }
    }
    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  so.bestClosingTime("YYNY");
  return 0;
}
