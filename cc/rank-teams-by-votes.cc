// http://leetcode.com/problems/rank-teams-by-votes/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/rank-teams-by-votes/discuss/525768/C%2B%2B-Short-solution-with-self-defined-lambda
  string rankTeams(vector<string> &votes) {
    string ret{votes[0]};
    const int n = votes[0].size();
    // 每一个字符对应每一列位置上的统计次数
    vector<vector<int>> rank(26, vector<int>(n, 0));
    for (auto &vote : votes) {
      for (int j = 0; j < n; j++) {
        rank[vote[j] - 'A'][j]++;
      }
    }

    sort(ret.begin(), ret.end(), [&](auto &l, auto &r) -> bool {
      // 如果这一列相等就比较下一列，这是vector的默认比较函数
      return rank[l - 'A'] > rank[r - 'A'] ||
             (rank[l - 'A'] == rank[r - 'A'] && l < r);
    });

    return ret;
  }
};

int main() {
  Solution so;
  vector<string> input{"ABC", "ACB", "ABC", "ACB", "ACB"};

  auto ret = so.rankTeams(input);
  cout << ret << endl;
}
