// http://leetcode.com/problems/maximum-score-words-formed-by-letters/description/
#include "xxx.h"

class Solution {
public:
  int maxScoreWords(vector<string> &words, vector<char> &letters,
                    vector<int> &score) {
    // 统计letter的个数
    vector<int> cnt(26, 0);
    for (auto &c : letters) {
      ++cnt[c - 'a'];
    }
    return dfs(words, 0, cnt, score);
  }

private:
  int dfs(vector<string> &words, int cur_index, vector<int> &cnt,
          vector<int> &score) {
    if (cur_index >= words.size()) {
      return 0;
    }
    // 怎么表达可取可不取
    auto skip_gain = dfs(words, cur_index + 1, cnt, score);
    bool valid = true;
    int with_gain = 0;

    vector<int> curcnt(cnt.begin(), cnt.end());
    for (auto &c : words[cur_index]) {
      // 不够
      if (--curcnt[c - 'a'] < 0) {
        valid = false;
      }
      with_gain += score[c - 'a'];
    }

    return max(skip_gain,
               valid ? with_gain + dfs(words, cur_index + 1,
                                       curcnt /*新的cnt递归下去*/, score)
                     : 0);
  }
};
