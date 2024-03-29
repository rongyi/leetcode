// http://leetcode.com/problems/number-of-ways-to-split-a-string/description/
#include "xxx.hpp"

class Solution {
public:
  int numWays(string s) {
    const long long n = s.size();
    const long long mod = pow(10, 9) + 7;

    int count =
        count_if(s.begin(), s.end(), [](char &c) -> bool { return c == '1'; });

    if (count % 3 != 0) {
      return 0;
    }

    if (count == 0) {
      // sum from 1 ==> n - 2
      return ((n - 1) * (n - 2) / 2) % mod;
    }

    const int part_total = count / 3;
    // left part ends
    int le = 0;
    int cur_count = (s[0] == '1');
    while (cur_count < part_total) {
      le++;
      cur_count += s[le] == '1';
    }
    // right part starts
    int rs = s.size() - 1;
    cur_count = (s[rs] == '1');
    while (cur_count < part_total) {
      rs--;
      cur_count += s[rs] == '1';
    }
    // 然后从第一个set有边界开始到第一个1之间的0都可以任意切
    int left_cut = 1;
    for (int i = le + 1; i < s.size() && s[i] == '0'; ++i) {
      ++left_cut;
    }

    int right_cut = 1;
    // 同左边界，这些0都可以切
    for (int i = rs - 1; i >= 0 && s[i] == '0'; --i) {
      ++right_cut;
    }

    return (left_cut % mod) * (right_cut % mod) % mod;
  }
};

int main() {
  Solution so;
  cout << so.numWays("01101") << endl;
}
