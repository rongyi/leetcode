// http://leetcode.com/problems/print-words-vertically/description/
#include "xxx.hpp"

class Solution {
public:
  vector<string> printVertically(string s) {
    int max_len = 0;

    vector<string> matrix;
    stringstream ss(s);
    string cur;
    stringstream retss;
    while (getline(ss, cur, ' ')) {
      matrix.push_back(cur);
      max_len = max(max_len, int(cur.size()));
    }
    vector<string> ret;
    const int m = matrix.size();
    const int n = max_len;

    for (int j = 0; j < n; j++) {
      string cur{};
      for (int i = 0; i < m; i++) {
        if (j >= matrix[i].size()) {
          cur.push_back(' ');
        } else {
          cur.push_back(matrix[i][j]);
        }
      }
      while (cur.back() == ' ') {
        cur.pop_back();
      }
      ret.push_back(cur);
    }

    return ret;
  }
};

int main() {
  Solution so;
  string input{"TO BE OR NOT TO BE"};
  so.printVertically(input);
}
