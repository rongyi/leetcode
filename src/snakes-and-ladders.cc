// http://leetcode.com/problems/snakes-and-ladders/description/
#include "xxx.h"

class Solution {
public:
  int snakesAndLadders(vector<vector<int>> &board) {
    const int n = board.size();
    unordered_map<int, int> step;
    step[1] = 0;

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      if (cur == n * n) {
        return step[cur];
      }

      for (int i = 1; i <= 6; i++) {
        int nxt = cur + i;
        if (nxt > n * n) {
          break;
        }
        auto v = calc(nxt, n);
        int nx = v[0];
        int ny = v[1];
        // 有捷径就走捷径
        if (board[nx][ny] != -1) {
          nxt = board[nx][ny];
        }
        if (!step.count(nxt)) {
          step[nxt] = step[cur] + 1;
          q.push(nxt);
        }
      }
    }

    return -1;
  }
private:
  // 序列号与坐标的对应关系
  vector<int> calc(int nxt, int n) {
    int x = (nxt - 1) / n;
    int y = (nxt - 1) % n;
    if (x % 2 == 1) {
      y = n - 1 - y;
    }
    x = n - 1 - x;
    return {x, y};
  }
};
