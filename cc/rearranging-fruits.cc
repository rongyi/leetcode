// https://leetcode.com/problems/rearranging-fruits/
#include "xxx.hpp"

class Solution {
public:
  long long minCost(vector<int> &basket1, vector<int> &basket2) {
    map<int, int> cnt;
    for (auto &num : basket1) {
      cnt[num]++;
    }
    for (auto &num : basket2) {
      // not plus, minus
      // means the one with zero value is kept in this array
      cnt[num]--;
    }
    vector<int> exch;
    for (auto &kv : cnt) {
      // odd count, can not split
      if (kv.second & 1) {
        return -1;
      }
      for (int i = 0; i < abs(kv.second) / 2; i++) {
        exch.push_back(kv.first);
      }
    }
    int sz = exch.size();
    nth_element(exch.begin(), exch.begin() + sz / 2, exch.end());
    int minx = min(*min_element(basket1.begin(), basket1.end()),
                   *min_element(basket2.begin(), basket2.end()));

    // Within each pair, there are two exchange methods:
    // 1. Direct exchange, the cost is the smaller number.
    // 2. Indirect exchange, choose another small number xxx as the
    // "intermediate", swap ai with x ans x with bj, the cost is 2x
    return accumulate(exch.begin(), exch.begin() + sz / 2, 0ll,
                      [&](long long acc, int cur) -> long long {
                        return acc + min(2 * minx, cur);
                      });
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> input1{4, 2, 2, 2};
  vector<int> input2{1, 4, 1, 2};
  cout << so.minCost(input1, input2) << endl;
  return 0;
}
