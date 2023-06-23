// https://leetcode.com/problems/snail-traversal/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> snail(vector<int> &input, int m, int n) {
    int sz = input.size();
    if (sz != m * n) {
      return {};
    }
    bool isDown = true;
    vector<vector<int>> ret(m, vector<int>(n, 0));
    int cnt = 0;
    int col = 0;
    int idx = 0;
    while (cnt < sz) {
      if (isDown) {
        for (int i = 0; i < m; i++) {
          ret[i][col] = input[idx++];
          cnt++;
        }
      } else {
        for (int i = m - 1; i >= 0; i--) {
          ret[i][col] = input[idx++];
          cnt++;
        }
      }

      isDown = !isDown;
      col++;
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{19, 10, 3,  7,  9, 8,  5,  2,  1, 17,
                    16, 14, 12, 18, 6, 13, 11, 20, 4, 15};
  auto ret = so.snail(input, 5, 4);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      cout << ret[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl;
}
