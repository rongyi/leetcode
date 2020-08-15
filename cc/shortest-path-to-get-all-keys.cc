// http://leetcode.com/problems/shortest-path-to-get-all-keys/description/
#include "xxx.h"

struct VisitRecord {
  pair<int, int> pos_;
  vector<int> keys_;
  int cur_cnt_;
  VisitRecord(pair<int, int> p, vector<int> keys, int cnt) {
    pos_ = p;
    keys_ = keys;
    cur_cnt_ = cnt;
  }

  int getState() {
    int ret = 0;
    for (int i = 0; i < keys_.size(); i++) {
      ret <<= 1;
      ret += keys_[i];
    }
    return ret;
  }
};

class Solution {
public:
  int shortestPathAllKeys(vector<string> &grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    dirs_ = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int num_key = 0;
    pair<int, int> start;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '@') {
          start = {i, j};
        } else if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
          num_key++;
        }
      }
    }
    queue<VisitRecord> q;
    vector<int> keys_start(num_key, 0);
    q.push(VisitRecord(start, keys_start, 0));
    int ret = -1;
    vector<vector<vector<int>>> vis((1 << num_key),
                                    vector<vector<int>>(m, vector<int>(n, 0)));

    while (!q.empty()) {
      auto cur = q.front();
      q.pop();

      int state = cur.getState();
      if (state == (1 << num_key) - 1) {
        ret = cur.cur_cnt_;
        break;
      }
      if (vis[state][cur.pos_.first][cur.pos_.second]) {
        continue;
      }
      vis[state][cur.pos_.first][cur.pos_.second] = 1;

      for (int i = 0; i < dirs_.size(); i++) {
        int nx = cur.pos_.first + dirs_[i][0];
        int ny = cur.pos_.second + dirs_[i][1];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
          continue;
        }

        auto keys = cur.keys_;

        if (grid[nx][ny] >= 'a' && grid[nx][ny] <= 'f') {
          int no = grid[nx][ny] - 'a';
          keys[no] = 1;
        } else if (grid[nx][ny] >= 'A' && grid[nx][ny] <= 'F') {
          // 没钥匙没法走
          int no = grid[nx][ny] - 'A';
          if (keys[no] == 0) {
            continue;
          }
        } else if (grid[nx][ny] == '#') {
          // wall 没法走
          continue;
        }
        q.push(VisitRecord({nx, ny}, keys, cur.cur_cnt_ + 1));
      }
    }

    return ret;
  }

private:
  vector<vector<int>> dirs_;
};
