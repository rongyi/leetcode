// http://leetcode.com/problems/cinema-seat-allocation/description/
#include "xxx.hpp"

class Solution {
public:
  int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats) {
    unordered_map<int, int> masks;
    for (auto &rsv : reservedSeats) {
      masks[rsv[0]] |= (1 << rsv[1]);
    }
    int ret = 0;
    for (auto kv : masks) {
      auto mask = kv.second;
      int cur_count = 0;

      if (((15 << 2) & mask) == 0) {
        cur_count++;
      }

      if (((15 << 6) & mask) == 0) {
        cur_count++;
      }

      // 两边都没有摊到，那这个时候看看中间行不行
      if ((cur_count == 0) && (((15 << 4) & mask) == 0)) {
        cur_count++;
      }

      ret += cur_count;
    }

    return ret + 2 * (n - masks.size());
  }

  int maxNumberOfFamiliesTLE(int n, vector<vector<int>> &reservedSeats) {
    vector<int> masks(n + 1, 0);
    for (auto rsv : reservedSeats) {
      masks[rsv[0]] |= (1 << rsv[1]);
    }
    int ret = 0;
    for (int i = 1; i < n + 1; ++i) {
      auto mask = masks[i];
      int cur_count = 0;

      if (((15 << 2) & mask) == 0) {
        cur_count++;
      }

      if (((15 << 6) & mask) == 0) {
        cur_count++;
      }

      if ((cur_count == 0) && (((15 << 4) & mask) == 0)) {
        cur_count++;
      }

      ret += cur_count;
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<vector<int>> input{{2, 1}, {1, 8}, {2, 6}};
  auto ret = so.maxNumberOfFamilies(3, input);
  cout << ret << endl;
}
