// http://leetcode.com/problems/battleships-in-a-board/description/
#include "xxx.hpp"

class Solution {
public:
  int countBattleships(vector<vector<char>> &board) {
    int ret = 0;
    const int m = board.size();
    const int n = board[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'X' && ((i == 0 || board[i - 1][j] == '.') &&
                                   (j == 0 || board[i][j - 1] == '.'))) {
          ++ret;
        }
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<vector<char>> input{{'X', 'X', 'X'}};
  auto ret = so.countBattleships(input);
  cout << ret << endl;
}
