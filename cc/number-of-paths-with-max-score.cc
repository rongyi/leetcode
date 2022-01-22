// http://leetcode.com/problems/number-of-paths-with-max-score/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> pathsWithMaxScore(vector<string> &board) {
    const int mod = pow(10, 9) + 7;
    const int n = board.size();
    dirs_ = {{1, 0}, {0, 1}, {1, 1}};

    vector<vector<int>> score(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> path(n + 1, vector<int>(n + 1, 0));
    board[0][0] = '0';
    board[n - 1][n - 1] = '0';
    path[0][0] = 1;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (board[i - 1][j - 1] == 'X') {
          continue;
        }
        for (auto &d : dirs_) {
          // prev x, prev y
          auto px = i - d[0];
          auto py = j - d[1];
          auto val = score[px][py] + (board[i - 1][j - 1] - '0');

          // C can be reached by three directions
          if (score[i][j] <= val) {
            path[i][j] =
                ((score[i][j] == val ? path[i][j] : 0) + path[px][py]) % mod;
            score[i][j] = val;
          }
        }
      }
    }

    return {path[n][n] ? score[n][n] : 0, path[n][n]};
  }

private:
  vector<vector<int>> dirs_;
};

int main() {
  Solution so;
  vector<string> input{"E23", "2X2", "12S"};
  so.pathsWithMaxScore(input);
}
