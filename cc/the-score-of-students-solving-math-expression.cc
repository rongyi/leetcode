// https://leetcode.com/problems/the-score-of-students-solving-math-expression
#include "xxx.h"

class Solution {
public:
  int scoreOfStudents(string s, vector<int> &answers) {
    int sz = s.size();
    int correct = 0;
    // note the equal case
    // 1+2+3
    //    ^ ^
    //    i i the last case should cover 3
    for (int i = 1, j = 0; i <= s.size(); i += 2) {
      if (i == sz || s[i] == '+') {
        int mul = 1;
        for (; j < i; j += 2) {
          mul *= s[j] - '0';
        }
        correct += mul;
      }
    }
    vector<vector<unordered_set<int>>> memo(sz + 1,
                                            vector<unordered_set<int>>(sz + 1));
    dfs(memo, s, 0, s.size());

    int score = 0;
    for (auto &curans : answers) {
      if (curans == correct) {
        score += 5;
      } else if (memo[0][sz].count(curans)) {
        score += 2;
      }
    }

    return score;
  }

private:
  void dfs(vector<vector<unordered_set<int>>> &memo, string &s, int st,
           int fin) {

    if (memo[st][fin].empty()) {
      if (fin - st == 1) {
        memo[st][fin].insert(s[st] - '0');
      }
      // 1+2*3
      // ^    ^ (init)
      // ^^     (split into this two case, include line below)
      //   ^  ^ (now this case split into two case below)
      //   ^^
      //     ^^
      for (int i = st + 1; i < fin; i += 2 /*one for op, one for num*/) {
        dfs(memo, s, st, i);
        dfs(memo, s, i + 1, fin);
        for (auto n1 : memo[st][i]) {
          for (auto n2 : memo[i + 1][fin]) {
            int n = s[i] == '*' ? n1 * n2 : n1 + n2;
            if (n <= 1000) {
              memo[st][fin].insert(n);
            }
          }
        }
      }
    }
  }
};

int main() {
  Solution so;
  vector<int> input{5};
  so.scoreOfStudents("1+2*3", input);
}
