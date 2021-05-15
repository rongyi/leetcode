// http://leetcode.com/problems/smallest-string-with-a-given-numeric-value/description/
#include "xxx.h"

class Solution {
public:
  // 不需要binary search
  string getSmallestString(int n, int k) {
    string start(n, 'a');
    // 这个函数都不需要
    // int cur_sum = ssum(start);
    int cur_sum = n;
    int cur_index = n - 1;
    // 条件会保证cur_index在范围内
    while (cur_sum < k) {
      int delta = k - cur_sum;
      // 拉满
      if (delta / 25) {
        start[cur_index] = 'z';

        cur_sum += 25;
        cur_index--;
      } else {
        start[cur_index] += (delta % 25);

        cur_sum += delta;
        cur_index--;
      }
    }

    return start;
  }

private:
  int ssum(const string &s) {
    int ret = 0;
    for (auto &c : s) {
      ret += (c - 'a') + 1;
    }
    return ret;
  }
};

int main() {
  Solution so;
  cout << so.getSmallestString(3, 27) << endl;
}
