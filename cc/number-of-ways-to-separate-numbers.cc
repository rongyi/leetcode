// http://leetcode.com/problems/number-of-ways-to-separate-numbers/description/
#include "xxx.hpp"

class Solution {
public:
  int numberOfCombinations(string num) {
    int n = num.size();
    int cur[n][n];
    int ways[n][n];
    int mod = 1e9 + 7;
    memset(cur, 0, sizeof(cur));
    memset(ways, 0, sizeof(ways));

    for (int i = n - 1; i >= 0; i--) {
      if (num[i] == '0') {
        continue;
      }
      // j is the end of first substring, length can be 1,
      // so j can be equal with i
      for (int j = n - 1, sum = 0; j >= i; j--) {
        // no second part, num[i][j] is the start substring
        if (j == n - 1) {
          cur[i][j] = 1;
        } else {
          int len = j - i + 1;
          int second_start = j + 1;
          int second_end = second_start + len - 1;
          int cnt = 0;
          // if the second substring is longer than the first -> must be bigger
          // ...                           shorter  ...        -> must be smaller
          //                               equal              -> need compare, memcmp is quicker
          // https://stackoverflow.com/questions/21106801/why-is-memcmp-so-much-faster-than-a-for-loop-check
          // second end is valid, and the second one is not smaller than the first one
          if (second_end <= n - 1 &&
              memcmp(&num[i], &num[second_start], len) <= 0) {
            cnt = (cnt + cur[second_start][second_end]) % mod;
          }
          // or the second one is longer than the first one
          if (second_end < n - 1) {
            cnt = (cnt + ways[second_start][second_end + 1]) % mod;
          }
          cur[i][j] = cnt;
        }
        ways[i][j] = sum = (sum + cur[i][j]) % mod;
      }
    }

    return ways[0][0];
  }
};

int main() {
  Solution so;
  int i = so.numberOfCombinations("327");
  cout << i << endl;
}
