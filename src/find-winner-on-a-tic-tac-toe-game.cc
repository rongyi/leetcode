// http://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/description/
#include "xxx.h"

class Solution {
public:
  string tictactoe(vector<vector<int>> &moves) {
    vector<unordered_map<int, int>> row(2, unordered_map<int, int>{});
    vector<unordered_map<int, int>> col(2, unordered_map<int, int>{});
    vector<unordered_map<int, int>> diag(2, unordered_map<int, int>{});
    vector<unordered_map<int, int>> anti(2, unordered_map<int, int>{});
    for (int i = 0; i < moves.size(); ++i) {
      if (++row[i % 2][moves[i][0]] == 3 || ++col[i % 2][moves[i][1]] == 3 ||
          ++diag[i % 2][moves[i][0] + moves[i][1]] == 3 ||
          ++anti[i % 2][moves[i][0] - moves[i][1]] == 3) {
        return i % 2 ? "B" : "A";
      }
    }
    if (moves.size() == 9) {
      return "Draw";
    }
    return "Pending";
  }
};
