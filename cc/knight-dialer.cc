// http://leetcode.com/problems/knight-dialer/description/
#include "xxx.hpp"

class Solution {
public:
  int knightDialer(int N) {
    const int mod = pow(10, 9) + 7;
    vector<long> cur(10, 1);
    vector<long> next(cur);
    for (int i = 2; i <= N; i++) {
      // 吓一跳合法的范围在main里有计算
      next[0] = (cur[4] + cur[6]) % mod;
      next[1] = (cur[6] + cur[8]) % mod;
      next[2] = (cur[7] + cur[9]) % mod;
      next[3] = (cur[4] + cur[8]) % mod;
      next[4] = (cur[0] + cur[3] + cur[9]) % mod;
      next[5] = 0;
      next[6] = (cur[0] + cur[1] + cur[7]) % mod;
      next[7] = (cur[2] + cur[6]) % mod;
      next[8] = (cur[1] + cur[3]) % mod;
      next[9] = (cur[4] + cur[2]) % mod;
      cur.swap(next);
    }

    return accumulate(cur.begin(), cur.end(), 0l) % mod;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> phone(3, vector<int>(3, 0));
  const int m = phone.size();
  const int n = phone[0].size();
  int initial = 1;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      phone[i][j] = initial++;
    }
  }
  unordered_map<int, vector<int>> valid_jumps;
  // calculate valid
  vector<vector<int>> jump{{-1, 2}, {-1, -2}, {-2, 1}, {-2, -1},
                           {1, 2},  {1, -2},  {2, 1},  {2, -1}};
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      // cur cordinate == i, j
      vector<int> validnext{};
      for (auto dir : jump) {
        int nx = i + dir[0];
        int ny = j + dir[1];
        if (nx < 0 || ny < 0) {
          continue;
        }
        // phone 0 position
        if (nx == 3 && ny == 1) {
          validnext.push_back(0);
        } else {
          if (nx >= m || ny >= n) {
            continue;
          }
          validnext.push_back(phone[nx][ny]);
        }
      }
      valid_jumps[phone[i][j]] = validnext;
    }
  }

  int x = 3;
  int y = 1;
  vector<int> valid_next{};
  for (auto dir : jump) {
    int nx = x + dir[0];
    int ny = y + dir[1];
    if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
      continue;
    }
    valid_next.push_back(phone[nx][ny]);
  }
  valid_jumps[0] = valid_next;

  for (auto kv : valid_jumps) {
    cout << kv.first << ":" << endl;
    cout << "  ";
    for (auto v : kv.second) {
      cout << v << " ";
    }
    cout << endl;
  }
  return 0;
}
