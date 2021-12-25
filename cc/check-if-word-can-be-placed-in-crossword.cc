// https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword/
#include "xxx.h"

class Solution {
public:
  bool placeWordInCrossword(vector<vector<char>> &board, string word) {
    string rw = word;
    reverse(rw.begin(), rw.end());
    int m = board.size();
    int n = board[0].size();
    vector<vector<char>> transpose(n, vector<char>(m, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        transpose[j][i] = board[i][j];
      }
    }
    return check(board, word) || check(board, rw) || check(transpose, word) ||
           check(transpose, rw);
  }

private:
  bool check(vector<vector<char>> &board, string &word) {
    int m = board.size();
    int n = board[0].size();
    int wlen = word.size();
    vector<vector<int>> flow(m, vector<int>(n, -1));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        // fresh start or in *valid* transition process
        if (j == 0 || board[i][j - 1] == '#' ||
            (j > 0 && flow[i][j - 1] != -1) /*valid transition process*/) {
          int pos = 0;
          if (j > 0) {
            pos = flow[i][j - 1] + 1;
          }
          if (board[i][j] == ' ' || board[i][j] == word[pos]) {
            if (pos == wlen - 1) {
              // almost return true, but we need to check the ending value
              if (j == n - 1 || board[i][j + 1] == '#') {
                return true;
              }
            } else {
              flow[i][j] = pos;
            }
          }
        }
      }
    }
    return false;
  }
};

int main() {
  Solution so;
  vector<vector<char>> input{{' '}, {'#'}, {'o'}, {' '}, {'t'},
                             {'m'}, {'o'}, {' '}, {'#'}, {' '}};
  so.placeWordInCrossword(input, "octmor");
}
