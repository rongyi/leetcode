// https://leetcode.com/problems/plates-between-candles/
#include "xxx.h"

class Solution {
public:
  vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries) {
    int sz = s.size();
    // normalize star index to candle index
    // for start we normalize it to right candle
    // for end we normalize it to left candle
    vector<int> right_candles(sz, 0);
    vector<int> left_candles(sz, 0);
    // and then we use prefix sum to count the number of candles
    // in the two normalized two index
    vector<int> prefix_start(sz, 0);

    for (int i = 0, start_cnt = 0, left_candle = -1; i < sz; ++i) {
      if (s[i] == '*') {
        start_cnt++;
      } else {
        left_candle = i;

        prefix_start[i] = start_cnt;
      }
      left_candles[i] = left_candle;
    }
    for (int i = sz - 1, right_candle = sz; i >= 0; --i) {
      if (s[i] == '|') {
        right_candle = i;
      }
      right_candles[i] = right_candle;
    }
    vector<int> ret;
    for (auto &q : queries) {
      auto l = right_candles[q[0]];
      auto r = left_candles[q[1]];
      if (l >= r) {
        ret.push_back(0);
      } else {
        ret.push_back(prefix_start[r] - prefix_start[l]);
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<vector<int>> input{{1, 17}, {4, 5}, {14, 17}, {5, 11}, {15, 16}};
  auto ret = so.platesBetweenCandles("***|**|*****|**||**|*", input);
  for (auto v : ret) {
    cout << v << " ";
  }
  cout << endl;
}
