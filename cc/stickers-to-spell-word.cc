// http://leetcode.com/problems/stickers-to-spell-word/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/stickers-to-spell-word/discuss/108318/C%2B%2BJavaPython-DP-%2B-Memoization-with-optimization-29-ms-(C%2B%2B)
  int minStickers(vector<string> &stickers, string target) {
    const int n = stickers.size();
    // 记录每一个stcker的字符统计情况
    vector<vector<int>> scount(n, vector<int>(26, 0));
    for (int i = 0; i < n; i++) {
      for (char c : stickers[i]) {
        scount[i][c - 'a']++;
      }
    }
    // 作为一个cache
    unordered_map<string, int> dp;
    // empty string need no stickers
    dp[""] = 0;
    return recur(dp, scount, target);
  }

private:
  int recur(unordered_map<string, int> &dp, vector<vector<int>> &scount,
            string target) {
    // including empty string case
    if (dp.find(target) != dp.end()) {
      return dp[target];
    }
    int ret = numeric_limits<int>::max();
    const int n = scount.size();

    vector<int> cur_count(26, 0);
    for (auto c : target) {
      cur_count[c - 'a']++;
    }

    // using stickers
    for (int i = 0; i < n; i++) {
      // optimization
      if (scount[i][target[0] - 'a'] == 0) {
        continue;
      }
      string s;
      // apply a sticker
      for (int j = 0; j < 26; j++) {
        if (cur_count[j] - scount[i][j] > 0) {
          s += string(cur_count[j] - scount[i][j], 'a' + j);
        }
      }

      int tmp = recur(dp, scount, s);
      if (tmp != -1) {
        ret = min(ret, 1 + tmp);
      }
    }

    dp[target] = (ret == numeric_limits<int>::max() ? -1 : ret);

    return dp[target];
  }
};

int main() {
  Solution so;
  vector<string> input{"with", "example", "science"};
  auto ret = so.minStickers(input, "thehat");
  cout << ret << endl;
};
